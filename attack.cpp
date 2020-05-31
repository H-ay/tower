#include "attack.h"
#include<QPaintEvent>
#include<QDebug>
#include<QPixmap>
#include<QPushButton>
#include<enterbtton.h>
attack::attack(QWidget *parent) : QMainWindow(parent)
{
this->setFixedSize(900,600);
}
void attack:: paintEvent(QPaintEvent*){
    QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
