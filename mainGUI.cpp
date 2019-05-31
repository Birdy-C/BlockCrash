#include <iostream>
#include <queue>
#include <QtWidgets/QApplication>
#include "Widget.h"
#include "BlockGenerate.h"
#include "Board.h"

// user interface

int main(int argc, char* argv[]) {
    class BlockGenerate generateBlock;
    class Board myboard;
    int N;
    // histroy record
    int historynum = 5;
    vector<Board> que(historynum);
    int index = 0;
	//
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}