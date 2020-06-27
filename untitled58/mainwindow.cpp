#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlaylist>
#include<QMediaPlayer>
#include<Qpainter>
#include<QPaintEvent>
#include<QPushButton>
#include<QPixmap>
#include<button.h>
#include<youxi.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //����
    {   QMediaPlaylist*playlist=new QMediaPlaylist;
        QMediaPlayer * player = new QMediaPlayer;
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist->addMedia(QUrl("qrc:/sound/beijing.mp3"));
        player->setVolume(30);
        player->setPlaylist(playlist);
        player->play();
      }

   //��ʼ����
      this->setMinimumSize(900,600);//��С
   //��Ϸ���
    enterbtton *enter = new enterbtton(":/image/enter0.png");
    enter->setParent(this);
    enter->move(310,300);//���
    youxi *scence=new youxi;
    connect(enter,&QPushButton::clicked,this,[=](){
       //�����л�
        this->hide();
        scence->show();
});

   //�˳���Ϸ
    enterbtton *quit = new enterbtton(":/image/quit.png");
    quit->setParent(this);
   quit->move(310,400);

   connect(quit,&QPushButton::clicked,this,[=](){
  this->hide();

   });


}




MainWindow::~MainWindow()
{
    delete ui;
}
//��ʼ����
void MainWindow:: paintEvent(QPaintEvent*){

    QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
