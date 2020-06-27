#ifndef PANJU_H
#define PANJU_H


#include<QMath.h>
inline bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)
{
    const int xdif = point1.x() - point2.x();
    const int ydif = point1.y() - point2.y();
    const int distance = qSqrt(xdif * xdif + ydif * ydif);

    if (distance <= radius1 + radius2)//ÅÐ¶Ï¾àÀë
        return true;

    return false;
}
#endif // PANJU_H
