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
    //音乐
    {   QMediaPlaylist*playlist=new QMediaPlaylist;
        QMediaPlayer * player = new QMediaPlayer;
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist->addMedia(QUrl("qrc:/sound/beijing.mp3"));
        player->setVolume(30);
        player->setPlaylist(playlist);
        player->play();
      }

   //开始界面
      this->setMinimumSize(900,600);//大小
   //游戏入口
    enterbtton *enter = new enterbtton(":/image/enter0.png");
    enter->setParent(this);
    enter->move(310,300);//入口
    youxi *scence=new youxi;
    connect(enter,&QPushButton::clicked,this,[=](){
       //界面切换
        this->hide();
        scence->show();
});

   //退出游戏
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
//开始界面
void MainWindow:: paintEvent(QPaintEvent*){

    QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
