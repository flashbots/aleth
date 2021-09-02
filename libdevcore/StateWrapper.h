#include "OverlayDB.h"
#include "RLP.h"

using namespace std;
namespace dev
{
namespace eth
{
class StateWrapper
{
public:
    StateWrapper(OverlayDB);

    u256 getNonce(h256);
    u256 getBalance(h256);
    h256 getStorageRoot(h256);
    h256 getCodeHash(h256);
    std::string getRlp(h256);

private:
    OverlayDB _db;
};
}  // namespace eth
}  // namespace dev