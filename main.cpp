#include <iostream>
#include "BlockGenerate.h"
#include "Board.h"

int main() {
    class BlockGenerate generateBlock;
    class Board myboard;
    //std::cout << "Hello, World!" << std::endl;
    int N;
    while(1){
        cin >> N;
        myboard.addBlock(generateBlock.getblock(N));
        for(int i = 0 ; i < 10; i ++){
            cout << myboard.board[i] << endl;
        }
    }

    return 0;
}