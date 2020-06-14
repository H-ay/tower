#include "youxi.h"
#include "ui_youxi.h"
#include<Qpainter>
#include<QPaintEvent>
#include<QPushButton>
#include<QPixmap>
#include<button.h>
#include<map.h>
youxi::youxi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::youxi)
{
    ui->setupUi(this);
      this->setMinimumSize(1200,800);//大小



    m_map=new map(1,4);

    m_map->loadTowerPositions();//加载塔位置信息
    m_map->load_Points();//加载塔位
  /*  enterbtton *ee8 = new enterbtton(":/image/tawei.png");
    ee8->setParent(this);
    ee8->move(640,280);//塔的位置*/

}

youxi::~youxi()
{
    delete ui;
}

void youxi:: paintEvent(QPaintEvent*){

   /* QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);*/

    QPixmap cachePix(m_map->mapway);//加载地图背景
    QPainter cachePainter(&cachePix);

    foreach (const TowerPosition &towerPos, m_map->m_towerPositionsList)
        towerPos.draw(&cachePainter);//画塔的位置



    foreach (const QList<WayPoint*> wayPointlist, m_map->m_wayPointsList)
        foreach(const WayPoint *wayPoint,wayPointlist)
        wayPoint->draw(&cachePainter);//画路径点
    //drawWave(&cachePainter);
    //drawHP(&cachePainter);
    //drawPlayerGold(&cachePainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);

}
