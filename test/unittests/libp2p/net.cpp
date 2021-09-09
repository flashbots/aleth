// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libdevcore/Assertions.h>
#include <libdevcore/Worker.h>
#include <libdevcore/concurrent_queue.h>
#include <libdevcrypto/Common.h>
#include <libp2p/NodeTable.h>
#include <libp2p/Host.h>
#include <libp2p/Network.h>
#include <libp2p/UDP.h>
#include <test/tools/libtesteth/Options.h>
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <boost/test/unit_test.hpp>
#include <future>

using namespace std;
using namespace dev;
using namespace dev::test;
using namespace dev::p2p;
namespace ba = boost::asio;
namespace bi = ba::ip;

BOOST_AUTO_TEST_SUITE(network)

BOOST_FIXTURE_TEST_SUITE(net, TestOutputHelperFixture)

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
