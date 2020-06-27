#ifndef YOUXI_H
#define YOUXI_H

#include <QMainWindow>
#include<map.h>
#include<tower.h>
#include<towerposition.h>
#include<jianta.h>
#include<chaita.h>
#include<QList>
#include<QDialog>









namespace Ui {
class youxi;
}
class WayPoint;
class Enemy;
class Bullet;
class youxi : public QMainWindow
{
    Q_OBJECT

public:
    explicit youxi(QWidget *parent = 0);
    ~youxi();

void removedBullet(Bullet *bullet);
void getHpDamage(int damage = 1);
void removedEnemy(Enemy *enemy);
void awardGold(int gold);
void addBullet(Bullet *bullet);

 QList<Enemy *>   enemyList() const;
protected:
 void paintEvent(QPaintEvent*);//游戏界面
 void mousePressEvent(QMouseEvent *);
private:
    Ui::youxi *ui;
     map                        * m_map;
     QList<Tower*>			    m_towersList;
     QList<Enemy *>			    m_enemyList;
     QList<Bullet *>			    m_bulletList;
     jianta                     *dialog;
     chaita                      *ddialog;
     int                        m_choosemap,m_pointnumber;
     int						m_playrGold;
     int						m_playerHp;
     int						m_waves;
     bool					    m_gameEnded;
     bool					    m_gameWin;
     bool                       canload=false;
     int                            temp_kind;
     int                            temp_kindd;
     bool loadWave();
     void doGameOver();
     void drawWave(QPainter *painter);
     void drawHP(QPainter *painter);
     void drawPlayerGold(QPainter *painter);
     void preLoadWavesInfo();
private slots:
         void t_youxi(int i);
         void t_youxi_s(int i);
         void gameStart();
         void updateMap();//更新地图
         void gostart();
         void on_pushButton_clicked();//map1
         void on_pushButton_2_clicked();//map2

signals:
canstart();

};

#endif // YOUXI_H











