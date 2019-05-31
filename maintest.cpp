#include <iostream>
#include <queue>
#include "BlockGenerate.h"
#include "Board.h"

// user interface

int main() {
    class BlockGenerate generateBlock;
    //std::cout << "Hello, World!" << std::endl;
    int N;
    // histroy record
    int historynum;
    vector<Board> que(historynum);
    int T = 20;
    int sum = 0;
    for(int i = 0; i < T; i ++){
        class Board myboard;
        while(1){
            bool test = myboard.addBlock(generateBlock.getrandomblock());
            if(!test) break;
        }
        sum += myboard.score;
        cout << myboard.score << endl;
    }
    cout << "RESULT: " << sum / T << endl;

    return 0;
}