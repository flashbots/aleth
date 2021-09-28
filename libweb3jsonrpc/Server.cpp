//
// Created by Marcos Maceo on 9/28/21.
//

#include "Server.h"
#include <iostream>

#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>

using namespace jsonrpc;
using namespace std;

class ServerBase : public AbstractStubServer
{
public:
    ServerBase(AbstractServerConnector& connector, serverVersion_t type);

    virtual std::string ping(const std::string& param01) = 0;
};

string ServerBase::ping(const string& ping)
{
    return "Hello " + ping;
}
