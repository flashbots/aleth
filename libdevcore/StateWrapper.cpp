//
// Created by Marcos Maceo on 9/2/21.
//

#include "StateWrapper.h"


StateWrapper::StateWrapper(OverlayDB db) : _db(db) {}

u256 StateWrapper::getNonce(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[0].toInt<u256>();
}
u256 StateWrapper::getBalance(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[1].toInt<u256>();
}
h256 StateWrapper::getStorageRoot(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[2].toInt<u256>();
}
h256 StateWrapper::getCodeHash(h256 address)
{
    std::string stateBack = getRlp(address);

    RLP state(stateBack);
    return state[3].toInt<u256>();
}
std::string StateWrapper::getRlp(h256 address)
{
    return _db.lookupAux(address);
}