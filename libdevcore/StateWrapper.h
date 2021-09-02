//
// Created by Marcos Maceo on 9/2/21.
//

#ifndef ALETH_STATEWRAPPER_H
#define ALETH_STATEWRAPPER_H

#include "OverlayDB.h"
#include "RLP.h"

using namespace std;
class StateWrapper
{
    StateWrapper(OverlayDB);

    u256 getNonce(h256);
    u256 getBalance(h256);
    h256 getStorageRoot(h256);
    h256 getCodeHash(h256);
    std::string getRlp(h256);

private:
    OverlayDB _db;
};


#endif  // ALETH_STATEWRAPPER_H
