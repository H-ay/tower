#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<youxi.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent*);//开始界面
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
