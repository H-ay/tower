#ifndef MAP_H
#define MAP_H
#include "towerposition.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
/*#include "enemy.h"
#include "bullet.h"
#include "audioplayer.h"
#include "plistreader.h"
#include "update_tower.h"*/

#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>

class map
{
public:
    map(int map_number,int point_number);
    void loadTowerPositions();
    void loadPoint(QString num);
    void load_Points();

    QString                 mapway;
    QList <QString>                 pointsnumber;
    QList<QVariant>                 m_wavesInfo;
    QList<  QList<WayPoint *>>		m_wayPointsList;
     QList<TowerPosition>	m_towerPositionsList;
    QList<WayPoint *>		m_wayPointsList2;
    QList<WayPoint *>		m_wayPointsList3;
    QList<WayPoint *>		m_wayPointsList4;

private:
    QString                         mapnumber;

};

#endif // MAP_H
