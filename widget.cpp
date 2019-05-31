#include <qpainter.h>
#include <qpen.h>
#include <qimage.h>
#include "widget.h"
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	historynum = 5;
	que = vector<Board>(historynum);
	setWindow();
	//QPixmap pixmap("E:\\Code3\\BlockCrash\\show.png");
	ui->label_3->setScaledContents(true);
	ui->label_3->setPixmap(QPixmap("E:\\Code3\\BlockCrash\\show.png", 0, Qt::AutoColor));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setWindow() {
	ui->label->setText("Score: " + QString::number(myboard.score));
	ui->label_4->setText("");

	QImage tmp(400, 400, QImage::Format_RGB888 );
	QPainter painter(&tmp);
    QPen paintpen(Qt::white), paintpen2(Qt::gray), paintpen3(Qt::black);
	paintpen.setWidth(10);
	QRect rect(0,0,400,400);
    painter.fillRect(rect, Qt::white);
//	painter.fillRect(0, 0, 400, 400);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			painter.setPen(paintpen2);
			if (myboard.board[j][i]) {
				QRect rectt(40*i, 40*j, 40, 40);
				painter.fillRect(rectt, Qt::gray);
			}
			painter.setPen(paintpen3);
			painter.drawRect(40 * i, 40 * j, 39, 39);
			
		}
	}
	ui->label_2->setPixmap(QPixmap::fromImage(tmp));

}

void MainWindow::setN(int N) {
	// Ctrl - z
    if(N == 0){
		index += historynum - 1;
        index %= historynum;
        myboard = que[index];
		return;
    }
        // update history
    que[index] = myboard;
    index ++;
    index %= historynum;
	bool test = myboard.addBlock(generateBlock.getblock(N - 1));
	setWindow();
	if (!test)
		ui->label_4->setText("Loss! final Score" + QString::number(myboard.score));

}