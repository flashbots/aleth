#include "libweb3jsonrpc/Server.h"
#include <iostream>
#include <jsonrpccpp/client/connectors/httpserver.h>

using namespace jsonrpc;
using namespace std;


int main()
{
    HttpServer httpserver(8383);
    ServerBase s(httpserver, JSONRPC_SERVER_V1V2);  // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    cout << "Hit enter to stop the server" << endl;
    getchar();

    s.StopListening();

    return 0;
}