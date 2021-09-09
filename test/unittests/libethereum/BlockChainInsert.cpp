// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

/// @file
/// BlockChain test functions.
#include <boost/filesystem/operations.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include <libdevcore/FileSystem.h>
#include <libethcore/BasicAuthority.h>
#include <libethereum/BlockChain.h>
#include <libethereum/Block.h>
#include <libethereum/GenesisInfo.h>
#include <test/tools/libtesteth/TestHelper.h>
#include <test/tools/libtesteth/BlockChainHelper.h>
using namespace std;
using namespace json_spirit;
using namespace dev;
using namespace dev::eth;
