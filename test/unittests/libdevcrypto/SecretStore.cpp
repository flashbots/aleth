// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <fstream>
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include <json_spirit/JsonSpiritHeaders.h>
#include <libdevcrypto/SecretStore.h>
#include <libdevcore/CommonIO.h>
#include <libdevcore/TrieDB.h>
#include <libdevcore/TrieHash.h>
#include <libdevcore/TransientDirectory.h>
#include "MemTrie.h"
#include <test/tools/libtesteth/TestOutputHelper.h>
using namespace std;
using namespace dev;
using namespace dev::test;

namespace js = json_spirit;
namespace fs = boost::filesystem;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(Crypto)

BOOST_AUTO_TEST_SUITE_END()
