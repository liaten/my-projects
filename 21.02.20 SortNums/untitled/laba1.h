#ifndef LABA1_H
#define LABA1_H

#include <QDialog>

namespace Ui {
class Laba1;
}

class Laba1 : public QDialog
{
    Q_OBJECT

public:
    explicit Laba1(QWidget *parent = nullptr);
    ~Laba1();

private:
    Ui::Laba1 *ui;
};

#endif // LABA1_H
