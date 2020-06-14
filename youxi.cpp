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
      this->setMinimumSize(1200,800);//��С



    m_map=new map(1,4);

    m_map->loadTowerPositions();//������λ����Ϣ
    m_map->load_Points();//������λ
  /*  enterbtton *ee8 = new enterbtton(":/image/tawei.png");
    ee8->setParent(this);
    ee8->move(640,280);//����λ��*/

}

youxi::~youxi()
{
    delete ui;
}

void youxi:: paintEvent(QPaintEvent*){

   /* QPainter painter(this)  ;
    QPixmap pixmap(":/image/Bg1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);*/

    QPixmap cachePix(m_map->mapway);//���ص�ͼ����
    QPainter cachePainter(&cachePix);

    foreach (const TowerPosition &towerPos, m_map->m_towerPositionsList)
        towerPos.draw(&cachePainter);//������λ��



    foreach (const QList<WayPoint*> wayPointlist, m_map->m_wayPointsList)
        foreach(const WayPoint *wayPoint,wayPointlist)
        wayPoint->draw(&cachePainter);//��·����
    //drawWave(&cachePainter);
    //drawHP(&cachePainter);
    //drawPlayerGold(&cachePainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);

}
