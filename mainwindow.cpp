#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qpainter>
#include<QPaintEvent>
#include<QDebug>
#include<QPixmap>
#include<QPushButton>
#include<enterbtton.h>
#include<attack.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     this->setMinimumSize(900,600);
     ui->setupUi(this);

    enterbtton *enter = new enterbtton(":/image/enter0.png");
    enter->setParent(this);
    enter->move(310,300);


attack *scence=new attack;
connect(enter,&QPushButton::clicked,this,[=](){
this->close();
scence->show();
});




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: paintEvent(QPaintEvent*){
    QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
