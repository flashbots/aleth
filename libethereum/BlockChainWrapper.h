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
    h256Hash allKinFrom(h256 const& _parent, unsigned _generations) const;

    bool isKnow(h256 const& hash);
    bytes block(h256 const& _hash) const;
    BlockDetails parentHashOfBlock(h256 const& _hash) const;

private:
    OverlayDb state;
    std::unique_ptr<LastBlockHashesFace> m_lastBlockHashes;
};