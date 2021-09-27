/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_
#define JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_

#include "ModularServer.h"

namespace dev {
    namespace rpc {
        class DebugFace : public ServerInterface<DebugFace>
        {
            public:
                DebugFace()
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_getWitness", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::DebugFace::debug_getWitnessI);
                }
                inline virtual void debug_getWitnessI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_getWitness(request[0u].asString());
                }
                virtual Json::Value debug_getWitness(const std::string& param1) = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_
