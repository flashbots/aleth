#include "libweb3jsonrpc/Server.h"
//#include <jsonrpccpp/server/connectors/httpserver.h>
#include <iostream>

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