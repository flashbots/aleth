#include "Debug.h"
#include "JsonHelper.h"
#include <jsonrpccpp/common/exception.h>
#include <libdevcore/CommonIO.h>
#include <libdevcore/CommonJS.h>
#include <libethcore/CommonJS.h>
#include <libethereum/Client.h>
#include <libethereum/Executive.h>
#include <libethereum/StandardTrace.h>
using namespace std;
using namespace dev;
using namespace dev::rpc;
using namespace dev::eth;

Debug::Debug():
{}

Json::Value Debug::debug_getWitness(std::string const& blockNumber)
{
    Json::Value ret;
    try
    {
        ret["structLogs"] = blockNumber;
    }
    catch(Exception const& _e)
    {
        cwarn << diagnostic_information(_e);
    }
    return ret;
}
