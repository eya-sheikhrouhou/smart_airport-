#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/azizo/OneDrive/Bureau/aziz_repo/gestion_bagage/307841663_519072713563574_557044734057287878_n.png");
    ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}

