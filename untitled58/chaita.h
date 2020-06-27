#ifndef CHAITA_H
#define CHAITA_H

#include <QDialog>

namespace Ui {
class chaita;
}

class chaita : public QDialog
{
    Q_OBJECT

public:
    explicit chaita(QWidget *parent = 0);
    ~chaita();
signals:
    sendkindd(int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::chaita *ui;
};

#endif // CHAITA_H





