#include "waypoint.h"
#include <QPainter>
#include <QColor>

WayPoint::WayPoint(QPoint pos, const QPixmap &sprite/* = QPixmap(":/image/Points.png")*/)//路径点
    : m_pos(pos)
    , m_nextWayPoint(NULL)
    , m_sprite(sprite)
{
}

void WayPoint::setNextWayPoint(WayPoint *nextPoint)//下一个路径点
{
    m_nextWayPoint = nextPoint;
}

WayPoint* WayPoint::nextWayPoint() const
{
    return m_nextWayPoint;
}

const QPoint WayPoint::pos() const
{
    return m_pos;
}

void WayPoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::green);
    painter->drawPixmap(m_pos.x(), m_pos.y(), m_sprite);

    if (m_nextWayPoint)
        painter->drawLine(m_pos, m_nextWayPoint->m_pos);
    painter->restore();
}
