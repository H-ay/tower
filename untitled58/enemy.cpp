#include "enemy.h"
#include "waypoint.h"
#include "tower.h"
#include "panju.h"
#include "youxi.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>


static const int Health_Bar_Width = 20;

const QSize Enemy::ms_fixedSize(52, 52);

Enemy::Enemy(WayPoint *startWayPoint, youxi*game,int maxHp/*=40*/,qreal phydef/*=1*/,qreal magdef/*=0*/,qreal walkingspeed/*=1.0*/,int award/*=200*/ ,const QPixmap &sprite_d/* = QPixmap(":/image/enemy.png")*/,
             const QPixmap &sprite_h /*= QPixmap(":/image/enemy.png")*/,const QPixmap &sprite_v /*= QPixmap(":/image/enemy1.png")*/)
    : QObject(0)
    , m_active(false)
    , m_maxHp(maxHp)
    , m_currentHp(maxHp)
    , m_walkingSpeed(walkingspeed)
    , m_rotationSprite(0.0)
    , m_pos(startWayPoint->pos())
    , m_destinationWayPoint(startWayPoint->nextWayPoint())
    , m_game(game)
    , m_sprite_d(sprite_d)
    , m_sprite_h(sprite_h)
    , m_sprite_v(sprite_v)
    , m_phydef(phydef)
    , m_magdef(magdef)
    , m_award(award)
{
}

Enemy::~Enemy()
{

    m_attackedTowersList.clear();
    m_destinationWayPoint = NULL;
    m_game = NULL;
}


void Enemy::doActivate()
{
    m_active = true;
}



void Enemy::move()
{
    if (!m_active)
        return;

    if (collisionWithCircle(m_pos, 1, m_destinationWayPoint->pos(), 1))
    {
        // 敌人抵达了一个航点
        if (m_destinationWayPoint->nextWayPoint())
        {
            // 还有下一个航点
            m_pos = m_destinationWayPoint->pos();
            m_destinationWayPoint = m_destinationWayPoint->nextWayPoint();
        }
        else
        {
            // 表示进入基地
            m_game->getHpDamage();
            m_game->removedEnemy(this);
            return;
        }
    }

    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = m_destinationWayPoint->pos();
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化
    qreal movementSpeed = m_walkingSpeed;
    QVector2D normalized(targetPoint - m_pos);
    normalized.normalize();
    m_pos = m_pos + normalized.toPoint() * movementSpeed;

    // 确定敌人选择方向
    // 默认图片向左,需要修正180度转右
    m_intersecion_angle=qRadiansToDegrees(qAtan2(normalized.y(), normalized.x()));
    m_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x()));
}




void Enemy::draw(QPainter *painter) const
{
    if (!m_active)
        return;

    painter->save();

    QPoint healthBarPoint = m_pos + QPoint(-Health_Bar_Width / 2 - 5, -ms_fixedSize.height());
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);

    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)m_currentHp / m_maxHp * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);

    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    painter->translate(m_pos);
    // 绘制敌人
    if((m_intersecion_angle<135&&m_intersecion_angle>45)||(m_intersecion_angle>-135)&&(m_intersecion_angle<-45)){
        painter->rotate(m_rotationSprite+90);
        painter->drawPixmap(offsetPoint, m_sprite_v);
    }
    else painter->drawPixmap(offsetPoint, m_sprite_h);

    painter->restore();
}

void Enemy::getRemoved()
{
    if (m_attackedTowersList.empty())
        return;
    foreach (Tower *attacker, m_attackedTowersList)
        attacker->targetKilled();
    //此敌人已经阵亡
    static const QPoint offsetPoint2(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    m_game->removedEnemy(this);
}

void Enemy::getDamage(int damage,bool atkind)
{
    if(atkind) m_currentHp -= damage*(1-m_phydef);
    else m_currentHp -= damage*(1-m_magdef);

    // 阵亡,需要移除
    if (m_currentHp <= 0)
    {

        m_game->awardGold(m_award);
        getRemoved();
    }
}

void Enemy::getAttacked(Tower *attacker)
{
    m_attackedTowersList.push_back(attacker);
}

// 表明敌人已经逃离了攻击范围
void Enemy::gotLostSight(Tower *attacker)
{
    m_attackedTowersList.removeOne(attacker);
}

QPoint Enemy::pos() const
{
    return m_pos;
}



Enemy2_1::Enemy2_1(WayPoint *startWayPoint, youxi *game,int maxHp/*=40*/,qreal phydef/*=1*/,qreal magdef,qreal walkingspeed,int award ,const QPixmap &sprite_d,
                   const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy2_1::~Enemy2_1(){}


Enemy2_2::Enemy2_2(WayPoint *startWayPoint, youxi *game,int maxHp/*=40*/,qreal phydef/*=1*/,qreal magdef/*=0*/,qreal walkingspeed/*=1.0*/,int award/*=300*/ ,const QPixmap &sprite_d/* = QPixmap(":/image/enemy.png")*/,
                   const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy2_2::~Enemy2_2(){}


Enemy3_1::Enemy3_1(WayPoint *startWayPoint, youxi *game,int maxHp,qreal phydef,qreal magdef,qreal walkingspeed,int award ,const QPixmap &sprite_d,
                   const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy3_1::~Enemy3_1(){}


Enemy3_2::Enemy3_2(WayPoint *startWayPoint, youxi *game,int maxHp,qreal phydef,qreal magdef,qreal walkingspeed,int award ,const QPixmap &sprite_d,
                   const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy3_2::~Enemy3_2(){}


Enemy3_3::Enemy3_3(WayPoint *startWayPoint, youxi *game,int maxHp,qreal phydef,qreal magdef,qreal walkingspeed,int award ,const QPixmap &sprite_d,
                   const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy3_3::~Enemy3_3(){}


Enemy_boss::Enemy_boss(WayPoint *startWayPoint, youxi *game,int maxHp,qreal phydef,qreal magdef,qreal walkingspeed,int award ,const QPixmap &sprite_d,
                       const QPixmap &sprite_h,const QPixmap &sprite_v)
    : Enemy(startWayPoint,game,maxHp,phydef,magdef,walkingspeed,award,sprite_d,sprite_h,sprite_v)
{
}

Enemy_boss::~Enemy_boss(){}

