// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2016-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <thread>
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include <jsonrpccpp/common/exception.h>
#include <libweb3jsonrpc/AccountHolder.h>
#include <libweb3jsonrpc/Personal.h>
#include <libweb3jsonrpc/Eth.h>
#include <libdevcore/TransientDirectory.h>
#include <libdevcore/FileSystem.h>
#include <libethcore/KeyManager.h>
#include <libwebthree/WebThree.h>
#include <libp2p/Network.h>
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <test/tools/libtesteth/TestHelper.h>

// This is defined by some weird windows header - workaround for now.
#undef GetMessage

using namespace std;
using namespace dev;
using namespace dev::eth;
using namespace dev::p2p;

namespace dev
{
namespace test
{

BOOST_FIXTURE_TEST_SUITE(ClientTests, TestOutputHelperFixture)

BOOST_AUTO_TEST_SUITE_END()

}
}
