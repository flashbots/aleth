// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.
/** 
 * Crypto test functions.
 */

#include <libdevcore/Guards.h>
#include <secp256k1.h>
#include <cryptopp/keccak.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/sha.h>
#include <cryptopp/modes.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>
#include <cryptopp/dsa.h>
#include <libdevcore/Common.h>
#include <libdevcore/RLP.h>
#include <libdevcore/Log.h>
#include <boost/test/unit_test.hpp>
#include <libdevcore/SHA3.h>
#include <libdevcrypto/Hash.h>
#include <libdevcrypto/CryptoPP.h>
#include <libethereum/Transaction.h>
#include <test/tools/libtesteth/TestOutputHelper.h>
#include <test/tools/libtesteth/Options.h>

using namespace std;
using namespace dev;
using namespace dev::test;
using namespace dev::crypto;

namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(Crypto)

BOOST_AUTO_TEST_SUITE_END()

