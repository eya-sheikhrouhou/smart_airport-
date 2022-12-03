#ifndef AVION_H
#define AVION_H

#include "smtp.h"
#include "arduino.h"
#include <QMainWindow>
#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>


#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Avion
{
public:
    Avion();
    Avion(QString,QString,QString,int);

    QString get_id();
    QString get_airline();
    QString get_R_F_Date();

    void set_id(QString);
    void set_airline(QString);
    void set_R_F_Date(QString);

    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QString tester();

    QSqlQueryModel* tri();
    QSqlQueryModel* tri1();
    QSqlQueryModel * rechercher ( QString);


private:
    QString id;
    QString airline,R_F_Date;
    int num_flight;
};


#endif // AVION_H
