//
// Created by Birdy on 2019-05-31.
//

#ifndef BLOCKCRASH_BOARD_H
#define BLOCKCRASH_BOARD_H

#include <vector>
#include <bitset>
#include "BlockGenerate.h"

using namespace std;

class Board {
public:
    int score = 0; // the score for the game
    int calculateAIscore(); // the score for AI
    void update(); // deleted the filled rank/row
    vector<bitset<10>> board;
    bool addBlock(class Block block);



};


#endif //BLOCKCRASH_BOARD_H
