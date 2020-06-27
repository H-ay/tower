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
    void move();//�ϻ�
    void getDamage(int damage,bool atkind);//�յ��˺�
    void getRemoved();//���˾�Ų��
    void getAttacked(Tower *attacker);//�ж�����
    void gotLostSight(Tower *attacker);//�ж��뿪�����ж�
    QPoint pos() const;//��������λ�����

public slots:
    void doActivate();

private:
    bool			m_active;//�ж�����
    int				m_maxHp;//��Ѫ
    int				m_currentHp;//��ǰѪ��
    int             m_award;//�ͽ�

    qreal           m_phydef;//������
    qreal           m_magdef;//ħ������

    qreal			m_walkingSpeed;//����
    qreal			m_rotationSprite;//������ת�ĽǶ�
    qreal           m_intersecion_angle;//���������������ļн�

    QPoint			m_pos;//λ��
    WayPoint *		m_destinationWayPoint;//Ŀ���
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

