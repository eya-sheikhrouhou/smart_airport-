#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Vol
{
public:
    Vol();
    Vol(int,QString,QString);
    int getDATEVOL();
    QString getNom();
    QString getDestination();
    QSqlQueryModel * rechercher ( QString);
    QSqlQueryModel* tri();
void setDATEVOL(int);
    void setNom(QString);
    void setDestination(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    QString nom,destination;
    int datevol;
};

#endif // VOL_H
