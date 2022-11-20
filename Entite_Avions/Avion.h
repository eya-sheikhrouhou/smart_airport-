#ifndef AVION_H
#define AVION_H

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

    QSqlQueryModel* tri();
    QSqlQueryModel* tri1();
    QSqlQueryModel * rechercher ( QString);


private:
    QString id;
    QString airline,R_F_Date;
    int num_flight;
};


#endif // AVION_H
