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

	// MDZZ 我终于把图片配好路径了
	// show picture
	ui->label_3->setPixmap(QPixmap(":/images/show", 0, Qt::AutoColor));
    //ui->label_3->setPixmap(QPixmap("E:\\Code3\\BlockCrash\\show.png", 0, Qt::AutoColor));
    connectslots();
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
				QRect rectt(360 - 40 * i, 40 * j, 40, 40);
				painter.fillRect(rectt, Qt::gray);
			}
			painter.setPen(paintpen3);
			painter.drawRect(360 - 40 * i, 40 * j, 39, 39);
			
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
        setWindow();
		return;
    }
        // update history
    que[index] = myboard;
    index ++;
    index %= historynum;
	bool test = myboard.addBlock(generateBlock.getblock(N - 1));
	setWindow();
	if (!test)
		ui->label_4->setText("Game over! \n Final Score" + QString::number(myboard.score));

}

void MainWindow::connectslots() {
    connect(ui->pushButton, &QPushButton::pressed, ([this]{ setN(1); }));
    connect(ui->pushButton_2, &QPushButton::pressed, ([this]{ setN(2); }));
    connect(ui->pushButton_3, &QPushButton::pressed, ([this]{ setN(3); }));
    connect(ui->pushButton_4, &QPushButton::pressed, ([this]{ setN(4); }));
    connect(ui->pushButton_5, &QPushButton::pressed, ([this]{ setN(5); }));
    connect(ui->pushButton_6, &QPushButton::pressed, ([this]{ setN(6); }));
    connect(ui->pushButton_7, &QPushButton::pressed, ([this]{ setN(7); }));
    connect(ui->pushButton_8, &QPushButton::pressed, ([this]{ setN(8); }));
    connect(ui->pushButton_9, &QPushButton::pressed, ([this]{ setN(9); }));
    connect(ui->pushButton_10, &QPushButton::pressed, ([this]{ setN(10); }));
    connect(ui->pushButton_11, &QPushButton::pressed, ([this]{ setN(11); }));
    connect(ui->pushButton_12, &QPushButton::pressed, ([this]{ setN(12); }));
    connect(ui->pushButton_13, &QPushButton::pressed, ([this]{ setN(13); }));
    connect(ui->pushButton_14, &QPushButton::pressed, ([this]{ setN(14); }));
    connect(ui->pushButton_15, &QPushButton::pressed, ([this]{ setN(15); }));
    connect(ui->pushButton_16, &QPushButton::pressed, ([this]{ setN(16); }));
    connect(ui->pushButton_17, &QPushButton::pressed, ([this]{ setN(17); }));
    connect(ui->pushButton_18, &QPushButton::pressed, ([this]{ setN(18); }));
    connect(ui->pushButton_19, &QPushButton::pressed, ([this]{ setN(19); }));
    connect(ui->pushButton_20, &QPushButton::pressed, ([this]{ setN(0); }));

}
