// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

/// @file
/// Difficulty calculation tests.
#include <test/tools/libtesteth/TestHelper.h>
#include <test/tools/fuzzTesting/fuzzHelper.h>
#include <libethashseal/Ethash.h>
#include <libethashseal/GenesisInfo.h>
#include <libethereum/ChainParams.h>
#include <boost/filesystem/path.hpp>
using namespace std;
using namespace dev;
using namespace dev::eth;

namespace fs = boost::filesystem;
namespace js = json_spirit;

BOOST_AUTO_TEST_SUITE(DifficultyTests)

BOOST_AUTO_TEST_SUITE_END()
