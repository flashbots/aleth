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

/**
 * @brief Implements the blockchain database. All data this gives is disk-backed.
 * @threadsafe
 */

BlockChainWrapper::BlockChainWrapper(OverlayDB state)
{
    // TODO update
    _state = state;
    // Set last_block_hashes
}

std::vector<h256> lastBlockHashes()
{
    // TODO update
    std::vector<h256> latestHashes;
    return latestHashes;
}

/// Get all blocks not allowed as uncles given a parent (i.e. featured as uncles/main in parent,
/// parent + 1, ... parent + @a _generations).
/// @returns set including the header-hash of every parent (including @a _parent) up to and
/// including generation + @a _generations together with all their quoted uncles.
h256Hash BlockChainWrapper::allKinFrom(h256 const& _parent, unsigned _generations) const
{
    // TODO update
    if (_generations == 5)
    {
        _generations = _generations + 1;
    }
    return h256Hash();
}

bool BlockChainWrapper::isKnown(h256 const& hash)
{
    // TODO update
    h256 pep = hash;
    return false;
}

bytes BlockChainWrapper::block(h256 const& _hash) const {
    h256 pep2 = _hash;
    bytes pep = std::vector<byte>();
    return pep;
}

h256 BlockChainWrapper::parentHashOfBlock(h256 _hash)
{
    return _hash;
}
}  // namespace eth
}  // namespace dev
