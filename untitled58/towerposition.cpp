#include "towerposition.h"
#include <QPainter>

const QSize TowerPosition::ms_fixedSize(145, 100);

TowerPosition::TowerPosition(QPoint pos, const QPixmap &sprite /*= QPixmap(":/image/tawei.png")*/)
    : m_hasTower(false)
    , m_pos(pos)
    , m_sprite(sprite)
{
}

QPoint TowerPosition::getpos() const
{
    return this->m_pos;
}

const QPoint TowerPosition::centerPos() const//���ĵ�λ��
{
    QPoint offsetPoint(ms_fixedSize.width() / 2, ms_fixedSize.height() / 2);
    return m_pos + offsetPoint;
}

bool TowerPosition::containPoint(const QPoint &pos) const//�ж��Ƿ񱻰���������λ����
{
    bool isXInHere = m_pos.x() < pos.x() && pos.x() < (m_pos.x() + ms_fixedSize.width());
    bool isYInHere = m_pos.y() < pos.y() && pos.y() < (m_pos.y() + ms_fixedSize.height());
    return isXInHere && isYInHere;
}

bool TowerPosition::hasTower() const//�ж��Ƿ��Ѿ�����
{
    return m_hasTower;
}

void TowerPosition::setHasTower(bool hasTower/* = true*/)
{
    m_hasTower = hasTower;
}

void TowerPosition::draw(QPainter *painter) const//����
{
    painter->drawPixmap(m_pos.x(), m_pos.y(), m_sprite);
}
