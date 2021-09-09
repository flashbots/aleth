// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2018-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libaleth-interpreter/interpreter.h>
#include <libethereum/LastBlockHashesFace.h>
#include <libevm/EVMC.h>
#include <libevm/LegacyVM.h>
#include <test/tools/jsontests/vm.h>
#include <test/tools/libtesteth/BlockChainHelper.h>
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <boost/format.hpp>
#include <boost/test/unit_test.hpp>

using namespace dev;
using namespace dev::test;
using namespace dev::eth;


BOOST_FIXTURE_TEST_SUITE(LegacyVMSuite, TestOutputHelperFixture)
BOOST_FIXTURE_TEST_SUITE(LegacyVMCreate2Suite, LegacyVMCreate2TestFixture)


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
