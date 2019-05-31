//
// Created by Birdy on 2019-05-31.
//

#include "BlockGenerate.h"
#include <assert.h>
int numblock(vector<bitset<10>> p){
    int sum = 0;
    for(auto tp : p){
        sum += tp.count();
    }
    return sum;
}

BlockGenerate::BlockGenerate(){
    // All blocks
    vector<vector<vector<bool>>> BlockTemp{
            {{1}},
            {{1,1}},
            {{1},{1}},
            {{1,1,1}},
            {{1},{1},{1}},

            {{1,1}, {0,1}},
            {{1,1}, {1,0}},
            {{0,1}, {1,1}},
            {{1,0}, {1,1}},

            {{1,1}, {1,1}},

            {{1,1,1,1}},
            {{1},{1},{1},{1}},

            {{1,1,1},{0,0,1},{0,0,1}},
            {{1,1,1},{1,0,0},{1,0,0}},
            {{0,0,1},{0,0,1},{1,1,1}},
            {{1,0,0},{1,0,0},{1,1,1}},

            {{1,1,1},{1,1,1},{1,1,1}},

            {{1, 1, 1, 1, 1}},
            {{1}, {1}, {1}, {1}, {1}},

    };

    for(auto m: BlockTemp){
        class Block temp_block;
        temp_block.len = m[0].size();
        for(auto f : m){
            bitset<10> bit;
            for(int i = 0; i < f.size(); i ++){
                if(f[i]) bit.set(i);
            }
            temp_block.block.push_back(bit);
        }
        temp_block.score = numblock(temp_block.block);
        BlockRec.push_back(temp_block);
    }
}

class Block BlockGenerate::getrandomblock() {
    int t = rand() % BlockRec.size();
    return BlockRec.at(t);
}

class Block BlockGenerate::getblock(int i) {
    assert(i >= 0 && i < BlockRec.size());
    return BlockRec.at(i);
}
