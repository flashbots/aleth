// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

/// @file
/// Gas pricer tests
#include <libethashseal/Ethash.h>
#include <libethereum/BlockChain.h>
#include <libethereum/ChainParams.h>
#include <libethereum/GasPricer.h>
#include <libethereum/BasicGasPricer.h>
#include <test/tools/libtesteth/TestHelper.h>
#include <test/tools/libtestutils/BlockChainLoader.h>
#include <boost/filesystem/path.hpp>

using namespace std;
using namespace dev;
using namespace dev::eth;
using namespace dev::test;
namespace fs = boost::filesystem;


BOOST_FIXTURE_TEST_SUITE(GasPricer, TestOutputHelperFixture)

BOOST_AUTO_TEST_SUITE_END()
