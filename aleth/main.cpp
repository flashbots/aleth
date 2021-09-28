#include <thread>
#include <fstream>
#include <iostream>
#include <regex>
#include <signal.h>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>

#include <libdevcore/DBFactory.h>
#include <libdevcore/FileSystem.h>
#include <libdevcore/LoggingProgramOptions.h>
#include <libdevcrypto/LibSnark.h>
#include <libethashseal/Ethash.h>
#include <libethashseal/GenesisInfo.h>
#include <libethcore/Common.h>
#include <libethcore/KeyManager.h>
#include <libethereum/SnapshotImporter.h>
#include <libethereum/SnapshotStorage.h>
#include <libevm/VMFactory.h>
#include <libwebthree/WebThree.h>

#include <libweb3jsonrpc/AccountHolder.h>
#include <libweb3jsonrpc/Eth.h>
#include <libweb3jsonrpc/ModularServer.h>
#include "libweb3jsonrpc/Serverbase.h"
#include <libweb3jsonrpc/IpcServer.h>
#include <libweb3jsonrpc/Net.h>
#include <libweb3jsonrpc/Web3.h>
#include <libweb3jsonrpc/AdminNet.h>
#include <libweb3jsonrpc/AdminEth.h>
#include <libweb3jsonrpc/Personal.h>
#include <libweb3jsonrpc/Debug.h>
#include <libweb3jsonrpc/Test.h>

#include "MinerAux.h"
#include "AccountManager.h"

#include <aleth/buildinfo.h>

using namespace std;
using namespace dev;
using namespace dev::p2p;
using namespace dev::eth;
namespace po = boost::program_options;
namespace fs = boost::filesystem;
#include <iostream>

using namespace jsonrpc;
using namespace std;


int main()
{
    unique_ptr<rpc::SessionManager> sessionManager;
    unique_ptr<SimpleAccountHolder> accountHolder;
    unique_ptr<ModularServer<>> jsonrpcIpcServer;
    string jsonAdmin;

    using FullServer = ModularServer<
        rpc::EthFace,
        rpc::NetFace, rpc::Web3Face, rpc::PersonalFace,
        rpc::AdminEthFace, rpc::AdminNetFace,
        rpc::DebugFace, rpc::TestFace
        >;

    sessionManager.reset(new rpc::SessionManager());
    accountHolder.reset(new SimpleAccountHolder([&](){ return web3.ethereum(); }, getAccountPassword, keyManager, authenticator));
    auto ethFace = new rpc::Eth(*web3.ethereum(), *accountHolder.get());
    rpc::TestFace* testEth = nullptr;
    if (testingMode)
        testEth = new rpc::Test(*web3.ethereum());

    jsonrpcIpcServer.reset(new FullServer(
        ethFace, new rpc::Net(web3),
        new rpc::Web3(web3.clientVersion()), new rpc::Personal(keyManager, *accountHolder, *web3.ethereum()),
        new rpc::AdminEth(*web3.ethereum(), *gasPricer.get(), keyManager, *sessionManager.get()),
        new rpc::AdminNet(web3, *sessionManager.get()),
        new rpc::Debug(*web3.ethereum()),
        testEth
        ));
    auto ipcConnector = new IpcServer("geth");
    jsonrpcIpcServer->addConnector(ipcConnector);
    ipcConnector->StartListening();

    if (jsonAdmin.empty())
        jsonAdmin = sessionManager->newSession(rpc::SessionPermissions{{rpc::Privilege::Admin}});
    else
        sessionManager->addSession(jsonAdmin, rpc::SessionPermissions{{rpc::Privilege::Admin}});

    cout << "JSONRPC Admin Session Key: " << jsonAdmin << "\n";
    return 0;
}