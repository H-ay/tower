#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "youxi.h"

#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>
#include<string>
#include<panju.h>
const QSize Tower::ms_fixedSize(100, 100);

Tower::Tower(QPoint pos, youxi *game, const QPixmap &sprite/* = QPixmap(":/image/tower a1.png"*/)
    : m_atkind(true)
    , m_attacking(false)
    , m_attackRange(200)
    , m_damage(10)
    , m_fireRate(1000)

    , m_game(game)
    , m_pos(pos)
    , m_sprite(sprite)
    , m_cost(300)
{
    m_fireRateTimer = new QTimer(this);
    connect(m_fireRateTimer, SIGNAL(timeout()), this, SLOT(shootWeapon()));
}


Tower::~Tower()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}
void Tower::checkEnemyInRange()
{
    if (m_chooseEnemy)
    {
        // ���������,��Ҫ��ת��̨��׼����
        // ������׼��
        QVector2D normalized(m_chooseEnemy->pos() - m_pos);
        normalized.normalize();

        // ����������빥����Χ
        if (!collisionWithCircle(m_pos, m_attackRange, m_chooseEnemy->pos(), 1))
            lostSightOfEnemy();
    }
    else
    {
        // ��������,���Ƿ��е����ڹ�����Χ��
        QList<Enemy *> enemyList = m_game->enemyList();
        foreach (Enemy *enemy, enemyList)
        {
            if (collisionWithCircle(m_pos, m_attackRange, enemy->pos(), 1))
            {
                chooseEnemyForAttack(enemy);
                break;
            }
        }
    }
}
void Tower::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::white);
    // ���ƹ�����Χ
    painter->drawEllipse(m_pos, m_attackRange, m_attackRange);

    // ����ƫת����,������+ƫ��=����
    static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    // ����������ѡ������
    painter->translate(m_pos);
    painter->drawPixmap(offsetPoint, m_sprite);
    painter->restore();
}

void Tower::attackEnemy()
{
    m_fireRateTimer->start(m_fireRate);
}

void Tower::chooseEnemyForAttack(Enemy *enemy)//ѡ��Ŀ�����
{
    m_chooseEnemy = enemy;
    attackEnemy();
    m_chooseEnemy->getAttacked(this);
}

void Tower::shootWeapon()
{
    Bullet *bullet = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet c.png"));

     bullet->move();
    m_game->addBullet(bullet);
}

void Tower::targetKilled()//���˽��빥����Χ
{
    if (m_chooseEnemy)
        m_chooseEnemy = NULL;

    m_fireRateTimer->stop();
}

void Tower::lostSightOfEnemy()//�����뿪������Χ
{
    m_chooseEnemy->gotLostSight(this);
    if (m_chooseEnemy)
        m_chooseEnemy = NULL;

    m_fireRateTimer->stop();
}


int Tower::getcost()//���ؽ��
{
    return m_cost;
}
const QPoint Tower::getpos()//������ ��������Ϣ
{
    return this->m_pos;
}

int Tower::getype(){return 0;}//���ı�־��Ϊ��ʵ�������Ͳ��





Tower_A::Tower_A(QPoint pos, youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower(pos,game,sprite)

{
    m_atkind=true;
    m_attackRange=160;
    m_damage=20;
    m_fireRate=900;
    m_cost=300;
}


Tower_A::~Tower_A()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

int Tower_A::getype(){return 1;}

void Tower_A::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet a.png"));
    bullet1->move();
    m_game->addBullet(bullet1);


}




Tower_A_S::Tower_A_S(QPoint pos, youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower_A(pos,game,sprite)
{
    m_atkind=true;
    m_attackRange=200;
    m_damage=30;
    m_fireRate=750;
    m_cost=300;
}

int Tower_A_S::getype() {return 4;}

Tower_A_S::~Tower_A_S()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

void Tower_A_S::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet a.png"));
    bullet1->move();
    m_game->addBullet(bullet1);
    //�ӳ�30ms
    Bullet *bullet2 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet a.png"));
    bullet2->move();
    m_game->addBullet(bullet1);
    //ͬʱ����������˵�ʵ�ֻ�û�����
}
//




Tower_Exp::Tower_Exp(QPoint pos, youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower(pos,game,sprite)
{
    m_atkind=true;
    m_attackRange=140;
    m_damage=12;
    m_fireRate=2000;
    m_cost=300;
}


Tower_Exp::~Tower_Exp()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

void Tower_Exp::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet b.png"));
    bullet1->move();
    m_game->addBullet(bullet1); //�ӳ�30ms

    //ͬʱ����������˵�ʵ�ֻ������
}

int Tower_Exp::getype(){return 2;}

Tower_Exp_S::Tower_Exp_S(QPoint pos, youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower_Exp(pos,game,sprite)
{
    m_atkind=true;
    m_attackRange=160;
    m_damage=40;
    m_fireRate=1800;
    m_cost=300;
}

int Tower_Exp_S::getype(){return 5;}

Tower_Exp_S::~Tower_Exp_S()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

void Tower_Exp_S::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet b.png"));
    bullet1->move();
    m_game->addBullet(bullet1);

}





Tower_M::Tower_M(QPoint pos,youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower(pos,game,sprite)
{
    m_atkind=false;
    m_attackRange=140;
    m_damage=15;
    m_fireRate=1250;
    m_cost=150;
}

int Tower_M::getype(){return 3;}

Tower_M::~Tower_M()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

void Tower_M::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet c.png"));
    bullet1->move();
    m_game->addBullet(bullet1);
    //ͬʱ����������˵�ʵ�ֻ�û�����
}




Tower_M_S::Tower_M_S(QPoint pos, youxi *game, const QPixmap &sprite /*= QPixmap(":/image/enemy1.png")*/)
    : Tower_M
      (pos,game,sprite)
{
    m_atkind=false;
    m_attackRange=200;
    m_damage=12;
    m_fireRate=1100;
    m_cost=400;
}


int Tower_M_S::getype() {return 6;}

Tower_M_S::~Tower_M_S()
{
    delete m_fireRateTimer;
    m_fireRateTimer = NULL;
}

void Tower_M_S::shootWeapon()
{
    Bullet *bullet1 = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game, m_atkind,QPixmap(":/image/bullet c.png"));
    bullet1->move();
    m_game->addBullet(bullet1); //�ӳ�30ms

    //ͬʱ����������˵�ʵ�ֻ�û�����
}
