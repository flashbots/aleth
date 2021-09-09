// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.
#include <fstream>
#include <boost/test/unit_test.hpp>
#include <json_spirit/JsonSpiritHeaders.h>
#include <libdevcore/CommonIO.h>
#include <libdevcore/TrieDB.h>
#include <libdevcore/TrieHash.h>
#include <libdevcore/StateCacheDB.h>
#include "MemTrie.h"
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <test/tools/libtesteth/Options.h>
#include <boost/filesystem/path.hpp>

using namespace std;
using namespace dev;
using namespace dev::test;

namespace fs = boost::filesystem;
namespace js = json_spirit;

BOOST_AUTO_TEST_SUITE(Crypto)

BOOST_FIXTURE_TEST_SUITE(Trie, TestOutputHelperFixture)

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
