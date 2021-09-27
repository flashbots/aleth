#pragma once
#include "DebugFace.h"
#include <libethereum/StandardTrace.h>

namespace dev
{

namespace eth
{
class Block;
class Client;
class Executive;
class State;

StandardTrace::DebugOptions debugOptions(Json::Value const& _json);
}

namespace rpc
{

class SessionManager;

class Debug: public DebugFace
{
public:
	explicit Debug();

	virtual RPCModules implementedModules() const override
	{
		return RPCModules{RPCModule{"debug", "1.0"}};
	}

    virtual Json::Value debug_getWitness(std::string const& blockNumber);

private:

	h256 blockHash(std::string const& _blockHashOrNumber) const;
    eth::State stateAt(std::string const& _blockHashOrNumber, int _txIndex) const;
    Json::Value traceTransaction(dev::eth::Executive& _e, dev::eth::Transaction const& _t, Json::Value const& _json);
	Json::Value traceBlock(dev::eth::Block const& _block, Json::Value const& _json);
};

}
}
