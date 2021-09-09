// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.
/** 
 * Trie test functions.
 */

#include <fstream>
#include <random>

#include <json_spirit/JsonSpiritHeaders.h>
#include <libdevcore/CommonIO.h>
#include <libethereum/BlockChain.h>
#include <libethashseal/GenesisInfo.h>
#include <test/tools/libtesteth/TestHelper.h>
#include <boost/filesystem/path.hpp>
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace dev;
using namespace dev::eth;
using namespace dev::test;

namespace fs = boost::filesystem;
namespace js = json_spirit;
