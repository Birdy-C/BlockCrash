//
// Created by Birdy on 2019-05-31.
//
#include <iostream>
#include "Board.h"
using namespace std;

bool Board::addBlock(class Block block) {
    int N = block.len;
    int M = block.block.size();
    int maxAIscore = INT_MIN;
    Board maxboard = *this;
    for(int i = 0; i <= boardsize - M; i ++){
        for(int j = 0; j <= boardsize - N; j ++){
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
    // check column
    for(int i = 0; i < boardsize; i ++){
        if(board[i].all()){
            board_t[i].reset();
            score += 10;
        }
    }

    // check rank
    for(int i = 0; i < boardsize; i ++){
        bool set = true;
        for(int j = 0; j < boardsize; j ++){
            if(!board[j][i]){
                set = false;
                break;
            }
        }
        if(set){
            for(int j = 0; j < boardsize; j ++){
                board_t[j][i] = false;
                score += 10;
            }
        }
    }
    board = board_t;
}

int Board::calculateAIscore() {
    return -calBorder()  - calBlock() * 2;
}

Board::Board():
    board(boardsize, bitset<boardsize>())
{}

int Board::calBlock() {
    int sum = 0;
    for(int i = 0; i < boardsize; i ++){
        sum += board[i].count();
    }
    return sum;
}

int Board::calBorder() {
    int sum = 0;
    // rank
    bitset<10> allone, t;
    allone = allone.flip();
    t = allone;
    for(int i = 0; i < boardsize; i ++){
        sum += (t ^ board[i]).count();
        t = board[i];
    }
    sum += (t ^ allone).count();

    //column
    for(int i = 0; i < boardsize; i ++){
        if(board[i][0] == 0) sum ++;
        if(board[i][boardsize - 1] == 0) sum ++;
        for(int j = 1; j < boardsize; j ++){
            if(board[i][j - 1] ^ board[i][j]) sum ++;
        }
    }
    return sum;
}

void Board::show() {
    for(int i = 0 ; i < 10; i ++){
        cout << board[i] << endl;
    }
}
