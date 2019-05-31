//
// Created by Birdy on 2019-05-31.
//

#include "Board.h"
const int boardsize = 10;

bool Board::addBlock(class Block block) {
    int N = block.len;
    int M = block.block.size();
    int maxAIscore = INT_MIN;
    Board maxboard = *this;
    for(int i = 0; i < boardsize - M; i ++){
        for(int j = 0; j < boardsize - N; j ++){
            Board temp = *this;
            bool possible = true;
            for(int t = 0; t < M; t ++)
            {
                if(((temp.board[i + t] & (block.block[t] << j)).any())){possible = false; break;}
                temp.board[i + t] |= (block.block[t] << j);
            }
            if(!possible) continue;
            temp.update();
            if(temp.calculateAIscore() > maxAIscore){
                maxAIscore = temp.calculateAIscore();
                maxboard = temp;
            }
        }
    }

    if(maxboard.board == this->board) return false;
    *this = maxboard;
    score += block.score;
    return true;
}

void Board::update() {
    vector<bitset<10>> board_t = board;
    for(int i = 0; i < boardsize; i ++){
        if(board[i].all())
            board_t[i].reset();
    }
    // TODO add rankcheck

    board = board_t;

}

int Board::calculateAIscore() {
    return 0;
}
