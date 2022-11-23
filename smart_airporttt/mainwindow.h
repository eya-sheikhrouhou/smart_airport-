#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<voyageur.h>
#include<QtCharts>
#include<QChartView>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include"arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void update_label();
private:
    QMediaPlayer* player;
    QVideoWidget* vw;

    Ui::MainWindow *ui;

    voyageur Etmp;
    QByteArray data;
   Arduino A;
   QString code;
      int arduino_connected;


};
#endif // MAINWINDOW_H
