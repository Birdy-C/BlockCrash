//
// Created by Birdy on 2019-05-31.
//

#ifndef BLOCKCRASH_BLOCKGENERATE_H
#define BLOCKCRASH_BLOCKGENERATE_H

#include <vector>
#include <bitset>
using namespace std;
class Block{
public:
    int score;
    int len;
    vector<bitset<10>> block;
};

class BlockGenerate {
    vector<class Block> BlockRec;



public:
    BlockGenerate();
    class Block getblock(int i);
    class Block getrandomblock();



};


#endif //BLOCKCRASH_BLOCKGENERATE_H
