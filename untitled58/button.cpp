#include "button.h"
#include<Qpainter>
#include<QPaintEvent>
#include<QPushButton>
#include<QPixmap>

enterbtton::enterbtton(QString pix) : QPushButton(0){
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
