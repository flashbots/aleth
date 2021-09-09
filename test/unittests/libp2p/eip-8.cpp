// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2016-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

/// @file
/// Forward-compatibility tests checking EIP-8 compliance.
#include <libp2p/Host.h>
#include <libp2p/NodeTable.h>
#include <libp2p/RLPXSocket.h>
#include <libp2p/RLPxHandshake.h>
#include <gtest/gtest.h>

using namespace std;
using namespace dev;
using namespace dev::p2p;
