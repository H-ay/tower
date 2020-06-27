#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>

class WayPoint;
class QPainter;
class youxi;
class Tower;


class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, youxi *game,int maxHp=40,qreal phydef=0,qreal magdef=0,
          qreal walkingspeed=1.0,int award=200,
          const QPixmap &sprite_d = QPixmap(":/image/enemy_1.png"),const QPixmap &sprite_h = QPixmap(":/image/enemy_1.png"),
          const QPixmap &sprite_v = QPixmap(":/image/enemy_1.png"));
    ~Enemy();

    void draw(QPainter *painter) const;
    void move();//废话
    void getDamage(int damage,bool atkind);//收到伤害
    void getRemoved();//死了就挪走
    void getAttacked(Tower *attacker);//判定受伤
    void gotLostSight(Tower *attacker);//判定离开估计判定
    QPoint pos() const;//敌人所在位置相关

public slots:
    void doActivate();

private:
    bool			m_active;//判断死活
    int				m_maxHp;//满血
    int				m_currentHp;//当前血量
    int             m_award;//赏金

    qreal           m_phydef;//物理护甲
    qreal           m_magdef;//魔法护甲

    qreal			m_walkingSpeed;//移速
    qreal			m_rotationSprite;//敌人旋转的角度
    qreal           m_intersecion_angle;//敌人与坐标轴横轴的夹角

    QPoint			m_pos;//位置
    WayPoint *		m_destinationWayPoint;//目标点
    youxi *	m_game;
    QList<Tower *>	m_attackedTowersList;

    const QPixmap	m_sprite_d;
    const QPixmap   m_sprite_h;
    const QPixmap   m_sprite_v;
    static const QSize ms_fixedSize;
};



class Enemy2_1:public Enemy{
public:
    Enemy2_1(WayPoint *startWayPoint, youxi *game,int maxHp=60,qreal phydef=0.15,qreal magdef=0,
             qreal walkingspeed=1.0,int award=350 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_1.png"),
             const QPixmap &sprite_h = QPixmap(":/image/enemy_1.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_1.png"));
    ~Enemy2_1();
};

class Enemy2_2:public Enemy{
public:
    Enemy2_2(WayPoint *startWayPoint, youxi *game,int maxHp=40,qreal phydef=0,qreal magdef=0,
             qreal walkingspeed=2,int award=250 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_2.png"),
            const QPixmap &sprite_h = QPixmap(":/image/enemy_2.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_2.png"));
    ~Enemy2_2();
};

class Enemy3_1:public Enemy{
public:
    Enemy3_1(WayPoint *startWayPoint, youxi *game,int maxHp=100,qreal phydef=0.20,qreal magdef=0,
             qreal walkingspeed=0.8,int award=500 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_3.png"),
            const QPixmap &sprite_h = QPixmap(":/image/enemy_3.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_3.png"));
    ~Enemy3_1();
};

class Enemy3_2:public Enemy{
public:
    Enemy3_2(WayPoint *startWayPoint, youxi *game,int maxHp=60,qreal phydef=0.10,qreal magdef=0,
             qreal walkingspeed=3   ,int award=400 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_4.png"),
             const QPixmap &sprite_h = QPixmap(":/image/enemy_4.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_4.png"));
    ~Enemy3_2();
};

class Enemy3_3:public Enemy{
public:
    Enemy3_3(WayPoint *startWayPoint, youxi *game,int maxHp=80,qreal phydef=0.10,qreal magdef=0.15,
             qreal walkingspeed=1.0,int award=400 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_5.png"),
             const QPixmap &sprite_h = QPixmap(":/image/enemy_5.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_5.png"));
    ~Enemy3_3();
};


class Enemy_boss:public Enemy{
public:
    Enemy_boss(WayPoint *startWayPoint,youxi *game,int maxHp=300,qreal phydef=0.30,qreal magdef=0.30,
             qreal walkingspeed=0.6,int award=600 ,const QPixmap &sprite_d = QPixmap(":/image/enemy_boss.png"),
               const QPixmap &sprite_h = QPixmap(":/image/enemy_boss.png"),const QPixmap &sprite_v = QPixmap(":/image/enemy_boss.png"));
    ~Enemy_boss();
};
#endif // ENEMY_H

