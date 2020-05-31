#ifndef ATTACK_H
#define ATTACK_H

#include <QMainWindow>
#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>

class attack : public QMainWindow
{
    Q_OBJECT
public:
    explicit attack(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // ATTACK_H
