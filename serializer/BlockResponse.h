//
// Created by Marcos Maceo on 8/17/21.

#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "struct_mapping/struct_mapping.h"

using namespace std;

struct JsonResponse
{
    std::string jsonrpc;
    BlockResponse result;
    int id;
};

struct BlockResponse
{
    std::string author;
    std::string difficulty;
    std::string extraData;
    std::string gasLimit;
    std::string gasUsed;
    std::string hash;
    std::string logsBloom;
    std::string miner;
    std::string mixHash;
    std::string nonce;
    std::string number;
    std::string parentHash;
    std::string receiptsRoot;
    std::string sha3Uncles;
    std::string size;
    std::string stateRoot;
    std::string totalDifficulty;
    std::string timestamp;
    std::string baseFeePerGas;
    std::vector<std::string> transactions;
    std::vector<std::string> uncles;
};
