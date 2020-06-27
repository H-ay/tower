#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
//#include<QPainter>
class Enemy;
class youxi;

class QPainter;

class Bullet : QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint m_currentPos READ currentPos WRITE setCurrentPos)

public:
    Bullet(QPoint startPos, QPoint targetPoint, int damage, Enemy *target,
        youxi *game, bool atkind, const QPixmap &sprite = QPixmap(":/image/bullet a.png"));

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

private slots:
    void hitTarget();

private:
    const QPoint	m_startPos;//发出子弹的塔的位置
    const QPoint	m_targetPos;//敌人位置
    const QPixmap	m_sprite;//贴图
    QPoint			m_currentPos;//子弹目前的位置点（？)
    Enemy *			m_target;//这发子弹的目标敌人
    youxi *	m_game;
    int				m_damage;//伤害数值

    bool            m_atkind;//伤害种类

    static const QSize ms_fixedSize;//？？？
};





#endif // BULLET_H



