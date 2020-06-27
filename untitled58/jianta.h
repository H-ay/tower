#ifndef JIANTA_H
#define JIANTA_H

#include <QDialog>

namespace Ui {
class jianta;
}

class jianta : public QDialog
{
    Q_OBJECT

public:
    explicit jianta(QWidget *parent = 0);
    ~jianta();
signals:
    void sendkind(int);



//void paintEvent(QPaintEvent*);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::jianta *ui;

};

#endif // JIANTA_H
