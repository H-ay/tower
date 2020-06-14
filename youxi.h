#ifndef YOUXI_H
#define YOUXI_H

#include <QMainWindow>
#include<map.h>
#include<tower.h>
namespace Ui {
class youxi;
}

class youxi : public QMainWindow
{
    Q_OBJECT

public:
    explicit youxi(QWidget *parent = 0);
    ~youxi();
void paintEvent(QPaintEvent*);//”Œœ∑ΩÁ√Ê

private:
    Ui::youxi *ui;
      map     * m_map;
     QList<Tower*>			m_towersList;
};

#endif // YOUXI_H

