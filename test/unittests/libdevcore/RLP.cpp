// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libdevcore/RLP.h>

#include <gtest/gtest.h>

using namespace dev;
using namespace std;

TEST(RLP, emptyArrayList)
{
    try
    {
        bytes payloadToDecode = fromHex("80");
        RLP payload(payloadToDecode);
        ostringstream() << payload;

        payloadToDecode = fromHex("с0");
        RLP payload2(payloadToDecode);
        ostringstream() << payload2;
    }
    catch (std::exception const& _e)
    {
        ADD_FAILURE() << "Exception: " << _e.what();
    }
}

TEST(RLP, actualSize)
{
    EXPECT_EQ(RLP{}.actualSize(), 0);

    bytes b{0x79};
    EXPECT_EQ(RLP{b}.actualSize(), 1);

    b = {0x80};
    EXPECT_EQ(RLP{b}.actualSize(), 1);

    b = {0x81, 0xff};
    EXPECT_EQ(RLP{b}.actualSize(), 2);
