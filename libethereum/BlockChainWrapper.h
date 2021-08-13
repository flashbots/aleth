#pragma once

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

namespace std
{
template <>
struct hash<pair<dev::h256, unsigned>>
{
    size_t operator()(pair<dev::h256, unsigned> const& _x) const
    {
        return hash<dev::h256>()(_x.first) ^ hash<unsigned>()(_x.second);
    }
};
}  // namespace std

namespace dev
{
class OverlayDB;

namespace eth
{
static const h256s NullH256s;

class State;
class Block;
class ImportPerformanceLogger;

DEV_SIMPLE_EXCEPTION(AlreadyHaveBlock);
DEV_SIMPLE_EXCEPTION(FutureTime);
DEV_SIMPLE_EXCEPTION(TransientError);
DEV_SIMPLE_EXCEPTION(FailedToWriteChainStart);
DEV_SIMPLE_EXCEPTION(UnknownBlockNumber);

// TODO: Move all this Genesis stuff into Genesis.h/.cpp
std::unordered_map<Address, Account> const& genesisState();

db::Slice toSlice(h256 const& _h, unsigned _sub = 0);
db::Slice toSlice(uint64_t _n, unsigned _sub = 0);

using BlocksHash = std::unordered_map<h256, bytes>;
using TransactionHashes = h256s;
using UncleHashes = h256s;

enum
{
    ExtraDetails = 0,
    ExtraBlockHash,
    ExtraTransactionAddress,
    ExtraLogBlooms,
    ExtraReceipts,
    ExtraBlocksBlooms
};

using ProgressCallback = std::function<void(unsigned, unsigned)>;

class VersionChecker
{
public:
    VersionChecker(boost::filesystem::path const& _dbPath, h256 const& _genesisHash);
};

/**
 * @brief Implements the blockchain database. All data this gives is disk-backed.
 * @threadsafe
 */

class BlockChainWrapper
{
public:
    BlockChainWrapper(OverlayDb state);
    ~BlockChainWrapper();

    LastBlockHashesFace const& lastBlockHashes() const { return *m_lastBlockHashes; }

    /// Get all blocks not allowed as uncles given a parent (i.e. featured as uncles/main in parent,
    /// parent + 1, ... parent + @a _generations).
    /// @returns set including the header-hash of every parent (including @a _parent) up to and
    /// including generation + @a _generations together with all their quoted uncles.
    h256Hash allKinFrom(h256 const&, unsigned) const;

    bool isKnow(h256 const&);
    bytes block(h256 const&) const;
    BlockDetails parentHashOfBlock(h256 const&) const;

private:
    OverlayDb state;
    std::unique_ptr<LastBlockHashesFace> m_lastBlockHashes;
};
}  // namespace eth
}  // namespace dev