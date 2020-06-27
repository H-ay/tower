#ifndef WAYPOINT_H
#define WAYPOINT_H
#include <QSize>
#include <QPoint>
#include <QPixmap>
class QPainter;

// 敌人移动的航线
class WayPoint
{
public:
    WayPoint(QPoint pos, const QPixmap &sprite = QPixmap(":/config/Points.plist"));

    void setNextWayPoint(WayPoint *nextPoint);
    WayPoint* nextWayPoint() const;
    const QPoint pos() const;

    void draw(QPainter *painter) const;

private:
    const QPoint		m_pos;
    WayPoint *			m_nextWayPoint;
    QPixmap		m_sprite;
};

#endif // WAYPOINT_H
