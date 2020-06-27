#ifndef TOWER_H
#define TOWER_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
//#include<QPainter>

//#include <enemy.h>
class youxi;



class QPainter;
class Enemy;

class QTimer;




class Tower : QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower a2.png"));
    ~Tower();

    void draw(QPainter *painter) const;
    void checkEnemyInRange();
    void targetKilled();
    void attackEnemy();
    void chooseEnemyForAttack(Enemy *enemy);
    //void removeBullet();
   // void damageEnemy();
    void lostSightOfEnemy();
     virtual int getype();

    int getcost();
    bool target;
    const QPoint getpos();

protected slots:
   virtual void shootWeapon();         //射击武器

protected:
    bool            m_atkind;   // ture对应物理，false对应魔法
    int             m_cost;     // 钱

    bool			m_attacking;
    int				m_attackRange;	// 代表塔可以攻击到敌人的距离
    int				m_damage;		// 代表攻击敌人时造成的伤害
    int				m_fireRate;		// 代表再次攻击敌人的时间间隔
    Enemy *			m_chooseEnemy;
    youxi *	         m_game;
    QTimer *		m_fireRateTimer;

    const QPoint	m_pos;
    const QPixmap	m_sprite;

    static const QSize ms_fixedSize;
};


class Tower_A:public Tower //1级箭塔
{
public:
    Tower_A(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower a1.png"));
    ~Tower_A();
     void shootWeapon();
    int getype();
};
class Tower_Exp:public Tower //1级炮塔
{
public:
    Tower_Exp(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower b1.png"));
    ~Tower_Exp();
     void shootWeapon();
    int getype();
};



class Tower_M:public Tower//1级魔法塔
{
public:
    Tower_M(QPoint pos, youxi*game, const QPixmap &sprite = QPixmap(":/image/tower c1.png"));
    ~Tower_M();
    void shootWeapon();
    int getype();

};



//升级版
class Tower_A_S:public Tower_A //2级箭塔
{
public:
    Tower_A_S(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower a2.png"));
    ~Tower_A_S();
      void shootWeapon();
    int getype();
};


class Tower_Exp_S:public Tower_Exp //2级炮塔
{
public:
    Tower_Exp_S(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower b2.png"));
    ~Tower_Exp_S();
       void shootWeapon();
    int getype();

};

class Tower_M_S:public Tower_M //2级魔法塔
{
public:
    Tower_M_S(QPoint pos, youxi *game, const QPixmap &sprite = QPixmap(":/image/tower c2.png"));
    ~Tower_M_S();
     void shootWeapon();
    int getype();

};


#endif // TOWER_H
