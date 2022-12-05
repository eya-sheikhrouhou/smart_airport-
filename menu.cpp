#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::hide_button() {
    //ui->employes->hide() ;

}



void menu::on_bagages_clicked()
{
    bagage.show();
    this->hide();

}

void menu::on_voyageurs_clicked()
{
    v.show();
    this->hide();
}

void menu::on_avion_clicked()
{
     a.show();
     this->hide();
}

void menu::on_employes_clicked()
{
    E.show();
    this->hide();
}

void menu::on_vols_clicked()
{
    v1.show();
    this->hide();
}
