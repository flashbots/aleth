// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.
#include <libdevcore/FixedHash.h>
#include <libdevcore/SHA3.h>

#include <gtest/gtest.h>

using namespace std;
using namespace dev;

TEST(FixedHash, comparisons)
{
    FixedHash<4> h1(sha3("abcd"));
    FixedHash<4> h2(sha3("abcd"));
    FixedHash<4> h3(sha3("aadd"));
    FixedHash<4> h4(0xBAADF00D);
    FixedHash<4> h5(0xAAAAAAAA);
    FixedHash<4> h6(0xBAADF00D);

    EXPECT_EQ(h1, h2);
    EXPECT_NE(h2, h3);

    EXPECT_GT(h4, h5);
    EXPECT_LT(h5, h4);
    EXPECT_LE(h6, h4);
    EXPECT_GE(h6, h4);
}
