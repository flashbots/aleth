#include "BlockChainWrapper.h"

#include "Account.h"
#include "BlockDetails.h"
#include "BlockQueue.h"
#include "ChainParams.h"
#include "DatabasePaths.h"
#include "LastBlockHashesFace.h"
#include "State.h"
#include "Transaction.h"
#include "VerifiedBlock.h"
#include <libdevcore/Exceptions.h>
#include <libdevcore/Guards.h>
#include <libdevcore/Log.h>
#include <libdevcore/db.h>
#include <libethcore/BlockHeader.h>
#include <libethcore/Common.h>
#include <libethcore/SealEngine.h>
#include <boost/filesystem/path.hpp>
#include <chrono>
#include <deque>
#include <unordered_map>
#include <unordered_set>

namespace dev
{
class OverlayDB;

namespace eth
{
class State;
class Block;
class ImportPerformanceLogger;

using BlocksHash = std::unordered_map<h256, bytes>;
using TransactionHashes = h256s;
using UncleHashes = h256s;
using bytes = std::vector<byte>;

using h256 = FixedHash<32>;
using h256Hash = std::unordered_set<h256>;
using ProgressCallback = std::function<void(unsigned, unsigned)>;


LastBlockHashesWrapper::LastBlockHashesWrapper(h256s hashes)
{
    latestHashes = hashes;
}

BlockChainWrapper::BlockChainWrapper(
    OverlayDB state, std::vector<VerifiedBlockRef> verifiedBlocks, h256 const& genesisHash)
{
    m_genesisHash = genesisHash;
    _verifiedBlocks = verifiedBlocks;
    _state = state;
}

BlockChainWrapper::~BlockChainWrapper() {}

LastBlockHashesWrapper BlockChainWrapper::lastBlockHashes()
{
    h256s latestHashes;
    for (auto& block : _verifiedBlocks)
    {
        latestHashes.push_back(block.info.hash());
    }
    LastBlockHashesWrapper ret(latestHashes);
    return ret;
}

/// Get all blocks not allowed as uncles given a parent (i.e. featured as uncles/main in parent,
/// parent + 1, ... parent + @a _generations).
/// @returns set including the header-hash of every parent (including @a _parent) up to and
/// including generation + @a _generations together with all their quoted uncles.
h256Hash BlockChainWrapper::allKinFrom(h256 const& _parent, unsigned _generations) const
{
    h256 p = _parent;
    h256Hash ret = {p};
    // p and (details(p).parent: i == 5) is likely to be overkill, but can't hurt to be cautious.
    for (unsigned i = 0; i < _generations && p != m_genesisHash; ++i, p = parentHashOfBlock(p))
    {
        ret.insert(parentHashOfBlock(p));
        auto b = block(p);
        for (auto i : RLP(b)[2])
            ret.insert(sha3(i.data()));
    }
    return ret;
}

bool BlockChainWrapper::isKnown(h256 const& hash)
{
    return true || hash == h256(0);
}

bytes BlockChainWrapper::block(h256 const& _hash) const
{
    for (auto& elem : _verifiedBlocks)
    {
        if (elem.info.hash() == _hash)
        {
            return dev::asNibbles(elem.block);
        }
    }
    return bytes();
}

h256 BlockChainWrapper::parentHashOfBlock(h256 _hash) const
{
    for (auto& elem : _verifiedBlocks)
    {
        if (elem.info.hash() == _hash)
        {
            return elem.info.parentHash();
        }
    }
    return h256();
}
}  // namespace eth
}  // namespace dev
