//
// Created by Marcos Maceo on 9/28/21.
//

#include "ServerBaseFace.h"
#include "Eth.h"
#include <jsonrpccpp/common/exception.h>
#include <libweb3jsonrpc/JsonHelper.h>
#include <libwebthree/WebThree.h>
#include <csignal>

using namespace std;
using namespace jsonrpc;
using namespace dev;
using namespace eth;
using namespace shh;
using namespace dev::rpc;

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
