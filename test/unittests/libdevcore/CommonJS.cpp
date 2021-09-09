// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libdevcore/CommonJS.h>

#include <gtest/gtest.h>

using namespace dev;
using namespace std;

TEST(CommonJS, toJS)
{
    h64 a("0xbaadf00ddeadbeef");
    u64 b("0xffff0000bbbaaaa");
    uint64_t c = 38990234243;
    bytes d = {0xff, 0x0, 0xef, 0xbc};

    EXPECT_EQ(toJS(a), "0xbaadf00ddeadbeef");
    EXPECT_EQ(toJS(b), "0xffff0000bbbaaaa");
    EXPECT_EQ(toJS(c), "0x913ffc283");
    EXPECT_EQ(toJS(d), "0xff00efbc");
}
