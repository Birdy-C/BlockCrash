#include <iostream>
#include <queue>
#include <QtWidgets/QApplication>
#include "widget.h"
#include "BlockGenerate.h"
#include "Board.h"

// user interface

int main(int argc, char* argv[]) {
//
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}