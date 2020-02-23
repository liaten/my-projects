#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "laba1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Laba1 window;
    window.setModal(true);
    window.exec();
}
