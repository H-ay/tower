#include "jianta.h"
#include "ui_jianta.h"
#include<button.h>
#include <QPainter>
#include <QtDebug>
#include<QPaintEvent>
#include<QPushButton>

jianta::jianta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jianta)
{
    ui->setupUi(this);
    this->setMinimumSize(500,300);
    /*
     *
     * 该代码是自己封装按钮enterbtton *e1 = new enterbtton(":/image/jian.png");
    e1->setParent(this);
    e1->move(100,120);

    connect(e1,&QPushButton::clicked,this,[=](){


       emit sendkind(3);
        this->hide();
    });
    enterbtton *e2 = new enterbtton(":/image/pao.png");
    e2->setParent(this);
    e2->move(200,120);
    connect(e2,&QPushButton::clicked,this,[=](){


         emit sendkind(1);
         this->hide();

    });
    enterbtton *e3 = new enterbtton(":/image/fa.png");
    e3->setParent(this);
    e3->move(300,120);
    connect(e3,&QPushButton::clicked,this,[=](){


   emit sendkind(2);
         this->hide();
    });*/
    ui->pushButton->setStyleSheet(QStringLiteral("background-image: url(:/image/pao.png);"));


    ui->pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/image/jian.png);"));

    ui->pushButton_3->setStyleSheet(QStringLiteral("background-image: url(:/image/fa.png);"));
}

jianta::~jianta()
{
    delete ui;

}

/*void jianta:: paintEvent(QPaintEvent*){

    QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}*/

void jianta::on_pushButton_clicked()
{

    emit sendkind(1);
    this->hide();
}


void jianta::on_pushButton_2_clicked()
{

    emit sendkind(3);
    this->hide();
}

void jianta::on_pushButton_3_clicked()
{
    emit sendkind(2);
    this->hide();
}


