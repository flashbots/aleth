//
// Created by Marcos Maceo on 9/2/21.
//

#include "StateWrapper.h"


StateWrapper::StateWrapper(OverlayDB db) : _db(db) {}

u256 getNonce(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[0].toInt<u256>();
}
u256 getBalance(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[1].toInt<u256>();
}
h256 getStorageRoot(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[2].toInt<u256>();
}
h256 getCodeHash(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[3].toInt<u256>();
}
std::string getRlp(h256 address)
{
    return _db.lookupAux(address);
}