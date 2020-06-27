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
    const QPoint	m_startPos;//�����ӵ�������λ��
    const QPoint	m_targetPos;//����λ��
    const QPixmap	m_sprite;//��ͼ
    QPoint			m_currentPos;//�ӵ�Ŀǰ��λ�õ㣨��)
    Enemy *			m_target;//�ⷢ�ӵ���Ŀ�����
    youxi *	m_game;
    int				m_damage;//�˺���ֵ

    bool            m_atkind;//�˺�����

    static const QSize ms_fixedSize;//������
};





#endif // BULLET_H



