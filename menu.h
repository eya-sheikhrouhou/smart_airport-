#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"bagages.h"
#include"gestion_voyageur.h"
#include"avions.h"
#include"gestionemployes.h"
#include"gestion_vol.h"


namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
   void hide_button() ;

private slots:
   void on_bagages_clicked();

   void on_voyageurs_clicked();

   void on_avion_clicked();

   void on_employes_clicked();

   void on_vols_clicked();

private:
    Ui::menu *ui;
    MainWindow bagage ;
    gestion_voyageur v;
    avions a;
    gestionEmployes E;
    gestion_vol v1;


};

#endif // MENU_H
