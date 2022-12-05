#ifndef GESTIONEMPLOYES_H
#define GESTIONEMPLOYES_H
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QMainWindow>
#include "employes.h"
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include"arduino.h"

#include <QWidget>

namespace Ui {
class gestionEmployes;
}

class gestionEmployes : public QDialog
{
    Q_OBJECT

public:
    explicit gestionEmployes(QDialog *parent = nullptr);
    ~gestionEmployes();
private slots:
    //void on_pushButton_clicked();

    void on_pushButton_ajouter_clicked();

   // void on_pushButton_3_clicked();//supprimer

    void on_pushButton_modifier_clicked();

    void on_pushButton_carte_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_clicked();

    void on_pushButton_search_tri_clicked();
    void update_label();//arduino

    void on_pushButton_supprimer_clicked();

private:
    Ui::gestionEmployes *ui;
    Employes Emp;
    int arduino_connected;
     Arduino A  ;
      QByteArray data ;
      QString code;
};

#endif // GESTIONEMPLOYES_H
