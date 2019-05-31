#include <iostream>
#include <queue>
#include "BlockGenerate.h"
#include "Board.h"

// user interface

int main() {
    class BlockGenerate generateBlock;
    class Board myboard;
    //std::cout << "Hello, World!" << std::endl;
    int N;
    // histroy record
    int historynum;
    vector<Board> que(historynum);
    int index = 0;
    while(1){
        cin >> N;

        // Ctrl - z
        if(N == 0){
            index += historynum - 1;
            index %= historynum;
            myboard = que[index];
            continue;
        }
        // update history
        que[index] = myboard;
        index ++;
        index %= historynum;

        //myboard.show();
        bool test = myboard.addBlock(generateBlock.getblock(N - 1));
        if(!test) break;
        cout << "SCORE:" << myboard.score << endl;
        myboard.show();
        cout << "BORDER" << myboard.calBorder() << endl;
    }
    return 0;
}