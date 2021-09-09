// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libdevcore/CommonIO.h>
#include <libdevcore/FixedHash.h>

#include <gtest/gtest.h>

TEST(core, toHex)
{
    dev::bytes b = dev::fromHex("f0e1d2c3b4a59687");
    EXPECT_EQ(dev::toHex(b), "f0e1d2c3b4a59687");
    EXPECT_EQ(dev::toHexPrefixed(b), "0xf0e1d2c3b4a59687");

    dev::h256 h("705a1849c02140e7197fbde82987a9eb623f97e32fc479a3cd8e4b3b52dcc4b2");
    EXPECT_EQ(dev::toHex(h), "705a1849c02140e7197fbde82987a9eb623f97e32fc479a3cd8e4b3b52dcc4b2");
    EXPECT_EQ(dev::toHexPrefixed(h),
        "0x705a1849c02140e7197fbde82987a9eb623f97e32fc479a3cd8e4b3b52dcc4b2");
}

