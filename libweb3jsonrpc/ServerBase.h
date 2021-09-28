//
// Created by Marcos Maceo on 9/28/21.
//

#ifndef ALETH_SERVERBASE_H
#define ALETH_SERVERBASE_H


class ServerBase
{
};

// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.


#pragma once

#include "ServerBaseFace.h"
#include "SessionManager.h"
#include <jsonrpccpp/common/exception.h>
#include <jsonrpccpp/server.h>
#include <libdevcore/Common.h>
#include <libethashseal/Ethash.h>
#include <libethereum/Client.h>
#include <iosfwd>
#include <memory>


namespace dev
{
class NetworkFace;
class KeyPair;
namespace eth
{
class AccountHolder;
struct TransactionSkeleton;
class Interface;
}  // namespace eth

}  // namespace dev

namespace dev
{
namespace rpc
{
// Should only be called within a catch block
std::string exceptionToErrorMessage();

/**
 * @brief JSON-RPC api implementation
 */
class ServerBase : public dev::rpc::ServerBaseFace
{
public:
    ServerBase() {}

    virtual RPCModules implementedModules() const override
    {
        return RPCModules{RPCModule{"server", "1.0"}};
    }

    virtual std::string ping(std::string const& message) override;
};

}  // namespace rpc
}  // namespace dev


#endif  // ALETH_SERVERBASE_H
