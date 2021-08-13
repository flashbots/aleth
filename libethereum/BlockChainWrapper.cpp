#include "BlockChainWrapper.h"

BlockChainWrapper::BlockChainWrapper(OverlayDb state)
{
    // Set last_block_hashes
}

LastBlockHashesFace const& lastBlockHashes() const
{
    return *m_lastBlockHashes;
}

/// Get all blocks not allowed as uncles given a parent (i.e. featured as uncles/main in parent,
/// parent + 1, ... parent + @a _generations).
/// @returns set including the header-hash of every parent (including @a _parent) up to and
/// including generation + @a _generations together with all their quoted uncles.
h256Hash BlockChainWrapper::allKinFrom(h256 const& _parent, unsigned _generations) const {}

bool BlockChainWrapper::isKnown(h256 const& hash)
{
    return false;
}

bytes BlockChainWrapper::block(h256 const& _hash) const {}

BlockDetails BlockChainWrapper::parentHashOfBlock(h256 const& _hash) const {}
