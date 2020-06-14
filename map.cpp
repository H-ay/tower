#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
//#include "enemy.h"
//#include "bullet.h"
#include "map.h"

#include "plistreader.h"
/*#include "update_tower.h"
#include "update_s.h"*/
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>

#include <typeinfo>
#include <cstring>
map::map(int map_number,int point_number)
{
    mapnumber=QString::number(map_number,10);
    for(int i=0;i<point_number;i++)
    {
        pointsnumber.push_back(QString::number(i+1,10));
    }
    mapway=":/image/Bg1.png";
}
void map::loadTowerPositions()//������λ����Ϣ
{   QString files=":/config/map"+mapnumber+"/TowersPosition.plist";
    QFile file(files);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
     //   QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    QList<QVariant> array = reader.data();
    foreach (QVariant dict, array)
    {
        QMap<QString, QVariant> point = dict.toMap();
        int x = point.value("x").toInt();//��ȡ����������Ϣ
        int y = point.value("y").toInt();
        m_towerPositionsList.push_back(QPoint(x, y));
    }

    file.close();
}
void map::loadPoint(QString num)//����·����
{   QList<WayPoint*> waypoint1;
    QString num1=num;
    QString files=":/config/map1/Points"+num1+".plist";
    QFile file(files);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
       // QMessageBox::warning(this, "Points", "Cannot Open Points.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    QList<QVariant> array = reader.data();//��ȡ����
    int t=0;
    foreach (QVariant dict, array)
    {
        QMap<QString, QVariant> point = dict.toMap();
        int x = point.value("x").toInt();//��ȡ·�����������Ϣ
        int y = point.value("y").toInt();
        WayPoint *wayPoint = new WayPoint(QPoint(x, y));
        waypoint1.push_back(wayPoint);
        if(t!=0){wayPoint->setNextWayPoint(waypoint1[t-1]);}
        t=t+1;//��Ϊ�㷨������Points�е��˳��Ӧ���Ǵ�β��ͷ
    }
    m_wayPointsList.push_back(waypoint1);
    file.close();
}
void map::load_Points()
{
    foreach (QString pointnumber, pointsnumber) {
       loadPoint(pointnumber);
    }
}
