#ifndef GESTION_VOYAGEUR_H
#define GESTION_VOYAGEUR_H

#include"ui_gestion_voyageur.h"
#include <QMainWindow>
#include<voyageur.h>
#include<QtCharts>
#include<QChartView>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include"arduino.h"

QT_BEGIN_NAMESPACE

namespace Ui { class gestion_voyageur; }
QT_END_NAMESPACE

class gestion_voyageur : public  QDialog
{
    Q_OBJECT

public:
    gestion_voyageur(QDialog *parent = nullptr);
    ~gestion_voyageur();

private slots:


    void on_pushButton_supprimer_clicked();


    void on_pushButton_modifier_clicked();

    void on_ajouter_clicked();

    void on_pushButton_trie_clicked();

    void on_pushButton_chercher_clicked();

    void on_table_voyageur_activated(const QModelIndex &index);

    int on_pushButton_clicked();

    //void on_playvideo_clicked();

   // void on__stopvideo_clicked();

    void on_actionon_triggered();

    void on_actionoff_triggered();




    void on_pushButton_3_clicked();

    void on_imprimer_clicked();

    void on_pushButton_4_clicked();
    void myfunction();
    void mydate();
    void stat();
    void update_labell();
private:
     Ui::gestion_voyageur *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;



    voyageur Etmp;
    QByteArray data;
   Arduino A;
   QString code;
      int arduino_connected;
      using QDialog::QDialog;


};
//#endif // MAINWINDOW_H


#endif // GESTION_VOYAGEUR_H
