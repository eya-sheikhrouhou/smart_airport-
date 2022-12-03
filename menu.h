#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"bagages.h"
#include"gestion_voyageur.h"
#include"avions.h"

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

private:
    Ui::menu *ui;
    MainWindow bagage ;
    gestion_voyageur v;
    avions a;

};

#endif // MENU_H
