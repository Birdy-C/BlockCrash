#include <QtWidgets/QWidget>
#include "BlockGenerate.h"
#include "Board.h"

#include "ui_widget.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
private:
    class BlockGenerate generateBlock;
    class Board myboard;
    int N;
    // histroy record
    int historynum;
    vector<Board> que;
    int index = 0;
	void setWindow();
	void connectslots();
	
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void setN(int N);

private:
    Ui::MainWindow *ui;
};
