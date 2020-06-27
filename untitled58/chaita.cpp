#include "chaita.h"
#include "ui_chaita.h"
#include<button.h>
#include <QPainter>
#include <QtDebug>

chaita::chaita(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chaita)
{
     ui->setupUi(this);
    this->setMinimumSize(200,300);
    /*
     *
     *该代码是自己封装按钮enterbtton *e1 = new enterbtton(":/image/chai.png");
    e1->setParent(this);
    e1->move(80,100);

    connect(e1,&QPushButton::clicked,this,[=](){

     emit sendkindd(1);

        this->hide();
    });
    enterbtton *e2 = new enterbtton(":/image/sheng.png");
    e2->setParent(this);
    e2->move(230,100);
    connect(e2,&QPushButton::clicked,this,[=](){

        emit sendkindd(0);
         this->hide();
    });*/

  
 ui->pushButton->setStyleSheet(QStringLiteral("background-image: url(:/image/chai.png);"));
  ui->pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/image/sheng.png);"));
}

chaita::~chaita()
{
    delete ui;
}

void chaita::on_pushButton_clicked()
{
    emit sendkindd(1);

       this->hide();
}

void chaita::on_pushButton_2_clicked()
{
    emit sendkindd(0);
     this->hide();
}
