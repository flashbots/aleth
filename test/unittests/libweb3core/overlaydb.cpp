// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include <libdevcore/DBFactory.h>
#include <libdevcore/OverlayDB.h>
#include <libethereum/Block.h>
#include <libethereum/BlockChain.h>
#include <test/tools/libtesteth/TestHelper.h>
#include <test/tools/libtesteth/BlockChainHelper.h>
#include <libethereum/GenesisInfo.h>
#include <libethereum/ChainParams.h>
#include <gtest/gtest.h>

using namespace std;
using namespace dev;
using namespace db;
using namespace dev::db;
using namespace dev::eth;
using namespace dev::test;
namespace utf = boost::unit_test;

TEST(OverlayDB, basicUsage)
{
    std::unique_ptr<db::DatabaseFace> db = DBFactory::create(DatabaseKind::MemoryDB);
    ASSERT_TRUE(db);

    OverlayDB odb(std::move(db));
    EXPECT_TRUE(!odb.get().size());

    // commit nothing
    odb.commit();

    string const value = "\x43";
    EXPECT_TRUE(!odb.get().size());

    odb.insert(h256(42), &value);
    EXPECT_TRUE(odb.get().size());
    EXPECT_TRUE(odb.exists(h256(42)));
    EXPECT_EQ(odb.lookup(h256(42)), value);

    odb.commit();
    EXPECT_TRUE(!odb.get().size());
    EXPECT_TRUE(odb.exists(h256(42)));
    EXPECT_EQ(odb.lookup(h256(42)), value);

    odb.insert(h256(41), &value);
    odb.commit();
    EXPECT_TRUE(!odb.get().size());
    EXPECT_TRUE(odb.exists(h256(41)));
    EXPECT_EQ(odb.lookup(h256(41)), value);
}

TEST(OverlayDB, auxMem)
{
    std::unique_ptr<db::DatabaseFace> db = DBFactory::create(DatabaseKind::MemoryDB);
    ASSERT_TRUE(db);

    OverlayDB odb(std::move(db));

    string const value = "\x43";
    bytes valueAux = fromHex("44");

    odb.insert(h256(42), &value);
    odb.insert(h256(0), &value);
    odb.insert(h256(numeric_limits<u256>::max()), &value);

    odb.insertAux(h256(42), &valueAux);
    odb.insertAux(h256(0), &valueAux);
    odb.insertAux(h256(numeric_limits<u256>::max()), &valueAux);

    odb.commit();

    EXPECT_TRUE(!odb.get().size());

    EXPECT_TRUE(odb.exists(h256(42)));
    EXPECT_EQ(odb.lookup(h256(42)), value);

    EXPECT_TRUE(odb.exists(h256(0)));
    EXPECT_EQ(odb.lookup(h256(0)), value);

    EXPECT_TRUE(odb.exists(h256(std::numeric_limits<u256>::max())));
    EXPECT_EQ(odb.lookup(h256(std::numeric_limits<u256>::max())), value);

    EXPECT_TRUE(odb.lookupAux(h256(42)) == valueAux);
    EXPECT_TRUE(odb.lookupAux(h256(0)) == valueAux);
    EXPECT_TRUE(odb.lookupAux(h256(std::numeric_limits<u256>::max())) == valueAux);
}

TEST(OverlayDB, rollback)
{
    std::unique_ptr<db::DatabaseFace> db = DBFactory::create(DatabaseKind::MemoryDB);
    ASSERT_TRUE(db);

    OverlayDB odb(std::move(db));
    bytes value = fromHex("42");

    odb.insert(h256(43), &value);
    EXPECT_TRUE(odb.get().size());
    odb.rollback();
    EXPECT_TRUE(!odb.get().size());
}

TEST(OverlayDB, readNBlocks)
{
    //     std::ifstream i("file.json");
    //     json j;
    //     i >> j;
    //
}

TEST(OverlayDB, insertWitness)
{
    std::unique_ptr<db::DatabaseFace> db = DBFactory::create(DatabaseKind::MemoryDB);
    ASSERT_TRUE(db);

    OverlayDB odb(std::move(db));

    EXPECT_TRUE(!odb.get().size());
//    auto hash = "sdlfkdslfk";
//    std::ifstream infile(hash);
//    std::string line;

    //    while (std::getline(infile, line))
    //    {
    ////        std::istringstream iss(line);
    ////        std::string key;
    ////        std::string value;
    ////
    ////        std::getline(iss, key, ',');
    ////        std::getline(iss, value, ',');
    //        bytes valueBytes = fromHex(value);
    //        odb.insertAux(h256(key), &valueBytes);
    //
    //        EXPECT_TRUE(odb.lookupAux(h256(key)) == valueBytes);
    //    }
//    std::string const& blockRlp = ;
//    TestBlock blockRlp;
//    TestBlock testBlock("f90277f90208a05a41d0e66b4120775176c09fcf39e7c0520517a13d2b57b18d33d342df038bfca01dcc4de8dec75d7aab85b567b6ccd41ad312451b948a7413f0a142fd40d4934794e6a7a1d47ff21b6321162aea7c6cb457d5476bcaa00e0df2706b0a4fb8bd08c9246d472abbe850af446405d9eba1db41db18b4a169a04513310fcb9f6f616972a3b948dc5d547f280849a87ebb5af0191f98b87be598a0fe2bf2a941abf41d72637e5b91750332a30283efd40c424dc522b77e6f0ed8c4b9010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000860153886c1bbd82b44382520b8252088455c426598b657468706f6f6c2e6f7267a0b48c515a9dde8d346c3337ea520aa995a4738bb595495506125449c1149d6cf488ba4f8ecd18aab215f869f86780862d79883d2000825208945df9b87991262f6ba471f09758cde1c0fc1de734827a69801ca088ff6cf0fefd94db46111149ae4bfc179e9b94721fffd821d38d16464b3f71d0a045e0aff800961cfce805daef7016b9b675c137a6a41a548f7b60a3484c06a33ac0");
//    EXPECT_TRUE(testBlock.blockHeader().hash());
//bytes valueBytes = fromHex( "f90211a0dc089bf98b185c858ec4b865117ff57ae79656a627437848e1c6d61e64dc8040a0614a746937f7fae4206b30e9c513e3224a5e0862a53efcbd50ddc23907a810d9a0220e8a43118054330d08e22af1be29b7c8eead661ec8f73a1de50741019eba76a05d4fce5d8df4b4dde9640219f0ca4104a229e1053ff7ed15fdf85208890cf203a0f95407904cb0e7910a7cde600caa0f8c32d997480c99d44347936bd7c638dc9ea0f1ea4a2be43078928ec8bed825293778121173755a146c2a44627923f7cc67fea07c868fbc08f09fe674b381f467d43f3d5b1aa86dac98fca1e0ea6cc7c1bb715ea0932107fc43830d02d9c20a142653d91a738ecdcb51d03ef36e016eaeab49323ba0014996de5cc0b2ee1aaa1ff209870a808d4c407f0ee4143f6e50fa7129466847a0feb4f03fd566f8ef81b82c633d3e9c1784f159e86613487c607ba2403b1088eba05ba4f56ba77b4d796a6901126e6ea7632a99e8437c62242b0182ede6e7a3cb59a017aaf2f4cb447bb9b776efd70a723ad6d801a93469b52170e49835de2ef38ca2a0f46bed067e2729a639ba465dd6bda652813f63d17c54b30d1edce879c4331902a0d8b23924722a6c570ff99dfe4215852eaa932f9237517c2c19e0a72b965cc66ba02967bdf8160fdff829f298fc127749a9342d839272b51c88a97c85ac4a10da02a02f679efc42e7f825f27ae68f5876bd506d0dbdd5bac1343fadff3630920f741480";
//odb.insertAux(h256("0x691fc4f4d21d10787902e8f3266711f1d640e75fedbeb406dc0b8d3096128436"), &valueBytes);
//valueBytes = fromHex( "f90211a028baa23d3062382310899793a9fdb01534b820fea601272fc713c4d8a3440203a055c03d814060ffb4923cf2d7fb5e9e3c8256f5759bedaad0bbe811ea848e3251a0bef8a03d28e3d6074a1754891fd5b19cecbe34e5ca22775d9f991cfb0329bda1a0766c61f38ecf6f10320dd6d0440c9e804e3425d19f4dece5faef4c5a70bb54e1a014eaa7e93570c884a41c976edda8bbf5169171fb6e0495ddcee1ac29c62d39caa05c6fcae1770cbefba440a5986677fc3e1302ad21ce92bcc85b8f30a5acd468bda074c16cd0a82a53953fb26422fed0f80f4c98edf567ec209f4bbd678b67ffae06a05869eddf0601bb6e01b96fbebde027c6bb298818d0a58cb55ba13642a83f0f81a008bcf12cc8584e9ecd38141b62968a1fb50954d4e34dc3022cea5bfc50c8ff8ba0f63d306b35ea9b9f6aba22719b97b15e12eb0bbcc6157a2fd2319b427977b034a0247f7e93c134fa5fa6bbeac737eb32340eb4876cb69018fbc8841422ac25e768a0180efac2dfc865de369b03b1c6cc0fa25c776c5d59f4a0cad98b4cd72666911ba091da6a990f5c6224faa732379f1ee1728d8daab8366fec9a80568b55b510e86ba04cafc03c0cd29d4fab5851a46a7e00d6afc44c58a255cf9265c6d7b2e98eb645a06422af5d855e5a36b5ab8f55dead3381b8901100ee847d7ffceb94790c5cb130a043caafcd43cadc01cea150b49c33b80c9efafb2199f68812cc241bd8262e744880";
//odb.insertAux(h256("0x2967bdf8160fdff829f298fc127749a9342d839272b51c88a97c85ac4a10da02"), &valueBytes);
//valueBytes = fromHex( "f901f1a0b3a36de009fa40468344e1fa0942e477e208237a6f11286de035958ce069cebba077d1fc9c8e712220eb84d9a9933c5e92eb0879c5358aaa8949d23d31664ae68f80a0d31c15e29a27218045ff7c1e65b3e27659394026be1c0fcd1e2205fe6e558b9da02b92d0dc968dd9d6057da8fc110d19f0b7373cc897ba7280522d5ccdd9a34a6ca02dde8893774861fd048051b1244a9a1802f4a5cf2b8248ba259bc2ed4f13068fa0b539144f583404bd6d0237772890d37356cca6117310842f798f8f5c847e4fbea028e1ca504a5a4dbc5b2d9eb3dc1a0d44da97fe04641d386b3cf458d22330ec46a0cab1e53213d344b3969cf800bb29a85c991f3096af83b18b5c16d769d0f96c3aa0744b06537e3cea527394aa7a9a464c7197be4f9138f08989d70541609d20db2da03fb172a53827ad5c1fc22e7d227ea51cf62b53c3152113019c9b48068ed7aca6a0aa63fd3b68758d055d7a298c5c8aae14a4b5d7b74790fc88e0285daff14be603a0e3ff207c89b1e7588cacf154c52af9fb82096f4599f3f588d0150379535a9062a0c59f52560ca4bf9bb180bbbbcafb908088b5ab1388b60b364692d00dc66abb29a0eaf31f6d96fc50fcd83cd84ae0292c0a11afddaedb94ee85ba31ec0af6f5414ca0dfb3c73f2ad5d1b88ed3609c4508a0989b55a0663f6001d02620f61228695fef80";
//odb.insertAux(h256("0x43caafcd43cadc01cea150b49c33b80c9efafb2199f68812cc241bd8262e7448"), &valueBytes);
//valueBytes = fromHex( "f89180a09b9f85631eb59095cdc5bdf03f3556b7d9933bf2eab9ea3720aba22e73023ff1808080a02b83b1ba2674a6ab622282af7a3e56aed6dc0e427eaef14a1711612cd86fdd42a08daed4d73ca8d6a29a96ec92c0c788f41c16aabc72cfd368d1ad818875c683ef80808080808080a0a14e1370978c58fc48f1e7a7f63dabd083c96e771dc1605885ae41d5d4047b6f8080";
//odb.insertAux(h256("0xb539144f583404bd6d0237772890d37356cca6117310842f798f8f5c847e4fbe"), &valueBytes);
//valueBytes = fromHex( "f8719f20bc78d73b85dc7c81af5cde0d18a7a6f26a6ecb3b74c5892e8dc052e84d77b84ff84d80896c6b935b8bbd400000a056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470";
//odb.insertAux(h256("0xa14e1370978c58fc48f1e7a7f63dabd083c96e771dc1605885ae41d5d4047b6f"), &valueBytes);
//valueBytes = fromHex( "f90211a0fd8b8ed81ce9c92162a37456bbc65eb09c59a59159fea166aef8d70e0560c697a0a9f3f642cd4621068258a1bc8098c467b3e617ddf480610b8d971f9b86f21c42a0941b16643a3f3a50687108cc498caa2cefacd7ec53756b8e6a8a2a9485dbf5ffa0f25ebb37fb04d725bcfbd38a7dbf260a4003c6149f6da3e5105fab580c7db8faa09b12dee4de8754528ffe313ca135149001394a72d7637c1b401f09e6f36df3eca0a39723c4f872a2596154bc430093799b5cc630b003f4f227b34b390aeb7e39fda0fdc112aa83dacbef35165f40d7e0ec7bcec10e4176597fe524f172b9e31ffc57a0ec11a92536f952138379a77edf5f6453f52fcc8ddaa48e2796ef38933fb87de3a0ac9e27f43f4965f73f11289b0d1fca7c212f977f41de8662f75adef09e47d135a0163b88927480aad3b83498c08aebf181abbbac93f4f4675ee58120664f2382a3a0c077ce8064cb20c31118af3b99cb4ac77a371a12b44058b44a25e7fbf8ab4288a059872941f5434694b9e22253251166f797b83691bcab723005692287a36cff95a0e1888dff1a3e4fd453fbcf657d55caae2f64d6eeb3a9b072c7cb15a3738c1488a0d7f40feec87a940c994e4200f68ce5cc0fdb527fca1741ac4c4d212afdcb4aaaa0a8440ef6e36d273b58c65344edab0583a03f09912d22e723dae51cc1d716d786a080931062cf57b118e1e88a9508b2dce6e2a6e4e73f388cc23aae90db1f53b3a880";
//odb.insertAux(h256("0x5ba4f56ba77b4d796a6901126e6ea7632a99e8437c62242b0182ede6e7a3cb59"), &valueBytes);
//valueBytes = fromHex( "f901d1a0262caa00fb7840634767dc16f70f8e9990f27f9c43d9ff8349a0b61c332fdf74a0872c5d2a9a5f8a004953b2e7228014ffc1ffbdd39a5e98bf8f1cbb55ac96a1ee80a0bae5ff57f2e7d370ad2a7444c09b70e0c688e469b71390677d3fb6f099b9f59ba04fed6ce8422f82708c15682dc3027a54b34faec61f9c070b08b11829d5971d0ea0908dcde7ffe13097de81b81e90042f6331ecacfda66cfd432b8a05f30bdd3812a0c112058db3b8cb4e477c0eb19722b661a23e5ccfd2c90e748040c522ea514054a0d882c86261fac4db5dfd8c8a5bacfa0a6523779194ffa19561c373c2556a6a2a80a0c4831de9432083d0d6bc381d1855e4d387600d8a2fb89a9e59fc77246316cbe8a0a70a8b973d101fd8ff04fbd3c04a433856997dbab21a38d01c6b995f6930fbf8a03f5cbfbbf8b0b47e7d624497dbdeb885a303210b88dd43d265670842d9d8a427a0f7f24ba0cf8f44642902c2093d8330f95814f604ae083136de238ec629337278a0348958af28c0a217eb8a4a65511701f39e5f98903e2f344233ae8a3d5e428c4ca0ae914b48b05e2af91032a9d648c2c71e8846a3ce7ccd5b0dacbe75f38ae53fc9a03ebe0ad64cbe3e2972c3a6a0158df85c9ddf6189d33dc893ff27b50ead8bbb3880";
//odb.insertAux(h256("0xfd8b8ed81ce9c92162a37456bbc65eb09c59a59159fea166aef8d70e0560c697"), &valueBytes);
//valueBytes = fromHex( "f87180808080a0d53c2af52b9847097c11843bd1251c52646048720938ba21375f8db8ccbcf64b808080a00266d8fb39448d40ea621d193aa8137522db79351194cdeb2c4812d508359638808080808080a0df2258a72399bcc4937b8c11404ddc137a0d588a2172c0883328cd049affa65480";
//odb.insertAux(h256("0xa70a8b973d101fd8ff04fbd3c04a433856997dbab21a38d01c6b995f6930fbf8"), &valueBytes);
//valueBytes = fromHex( "f8719f202121f7c68579158ac339baa264aa87365a93acd7530176ddd09bfa12c62cb84ff84d80890796e3ea3f8ab00000a056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470";
//odb.insertAux(h256("0x0266d8fb39448d40ea621d193aa8137522db79351194cdeb2c4812d508359638"), &valueBytes);
//valueBytes = fromHex( "f90211a07430fb380fdca6ed84c50bc135607d8397003825c153c9b1f4b8e11f941c5493a0c89713adb8fd959f421aea89b044a66b777ec90af329c176bc32b5a2000e3373a01172b111a81f1f8c0070c536c76a203a9c31e7d88dc55c049026227622d02217a01a7e76ab14f55f8dd90fc5a53cf93edd3102970c7db869e26327214d081baf28a016a6145b772b0ea0732e5368f0dfd61d676d396c71b6b4289b472b3765075290a04c686e626f75f57806fbb7b1de9276bacf53ac177ef967553c4e3d324f5c0a79a0d1be9cd30cc6468e7f1af92afa0da2ae58d78ae10db3ff8963271339ba4cb9e4a0e4c6e4399a5b251963ca1e3370c3d9f70773f5a1b4617f3d2fe2abc6519f10eba0b7b06f412e132c2b0aa7ccb9ab7b045ba0ada3ea06afa5ca18bd5ced0db1af07a068073d8bfdf6a393de6bd39cfafadd94c9b33aa04bd8cd5a039a026076434ccfa0bd23b2aa15460ff8fb30aee5913682222cffb0e0090f5ebd4df9a8be852ba2fba0e77e62232cb722dedab94c78aeb08e78c715a1dc66970d5277b4af056243db77a02e9a0cc2ddade0053338053b42b1905e20e169c3209fcb54c37946e24097861da0bb9bae6803c046e8ea74c8c47c732415c8a1eaac67fa6045b8f4c621c4f095cca016ee635418e034b76389c6651b4a5758f7c334caafb9f781530d606b375d3202a014fabf19a2cf2a646d801d657ecc54698a1972eb2e026af31a3e7632b5ebda9780";
//odb.insertAux(h256("0xf95407904cb0e7910a7cde600caa0f8c32d997480c99d44347936bd7c638dc9e"), &valueBytes);
//valueBytes = fromHex( "f901d1a0d88b88c0e54acbc0d051a5b186e351f9710217e9cf0e0b9cc0c9ec59457d4309a09a106e20261a522032001513598ad931d89f6811ef7e7d9685ff91c3bafc7121a03f13f4fd2ee516ef1afc073056a9905bce55b3f35cc5365df865014c7baae8fca01479201f2abdc5845158262b1967a1a4d3e73d6a21506c39063bbd42cc1a6eaba0f618960bf5b4cd9705014af96da401ea6703746d010c03665523cd03a373e9f9a0836eecfad198f25db064db8924ca8158daea7b78c3999f5c8c2b77523ea210f5a0d5b3eba3585b667f5e13d00bf216acb4aa57b39623047d60b8b0c0ad08ff1ffb80a022f00fc57402189b89a3478b8e0d96746b7b59bcf3330b29efb2f60548721d54a003554a55db00ea63712aa6bcc954635fafb9e5bf85b98fe2e13a9df5f00e1ebc80a0bed3ed82623b5591eb56d59ebe7560b01c6fed4fb165caf6cb11188dd7214960a05f100ba6893431b3db0d7ce666c1a7a34b2827e8d9d91a0d9cfae6273a7d4005a06845b69f70fca02e02d17262524f454e55f79bf12d4bf29a4903bf76767d6a82a0b4349b3d4ae6235648590c248e7d5df07ee87bd0978b002bec815655d8b8da5aa086db579b939f7f68e929768a98ec8402ff2214785312e9ddd168ff1a436259dd80";
//odb.insertAux(h256("0xbb9bae6803c046e8ea74c8c47c732415c8a1eaac67fa6045b8f4c621c4f095cc"), &valueBytes);
//valueBytes = fromHex( "f851a0d171ede5375406efca67c35bf64ef787a7e1319deeeb9a2a84426a316878909a8080808080808080808080a0ab0b8e76ada01578f395c4151a0cc4bc4b323ec56dbeb28d98aebad9c47f6a1680808080";
//odb.insertAux(h256("0x22f00fc57402189b89a3478b8e0d96746b7b59bcf3330b29efb2f60548721d54"), &valueBytes);
//valueBytes = fromHex( "f8719f20e16d49202e884407f85bb18daebe29216ea0e353494c957c29c2f2f317f9b84ff84d8089f3426785a8ab466000a056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470";
//odb.insertAux(h256("0xd171ede5375406efca67c35bf64ef787a7e1319deeeb9a2a84426a316878909a"), &valueBytes);

//    TestBlock genesis = TestBlockChain::defaultGenesisBlock();
//    TestBlockChain bc(genesis);
//
//    BlockChain& bcRef = bc.interfaceUnsafe();
//    Block block;
//    block.enact(&(VerifiedBlockRef some), bc);
//
//    block.enact(&(VerifiedBlockRef some), wrapper)
//    struct wrapper {
//        blockchain
//        overlaydb
//    };
//    - Modify the Block::enact;
}
