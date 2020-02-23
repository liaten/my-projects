#include "laba1.h"
#include "ui_laba1.h"

Laba1::Laba1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Laba1)
{
    ui->setupUi(this);
}

Laba1::~Laba1()
{
    delete ui;
}
