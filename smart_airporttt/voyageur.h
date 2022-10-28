#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class voyageur
{
public:
    voyageur(int,QString,QString,QString,QDate);
    //setters
    void setcin(int n);
    void setnom(QString n);
    void setprenom(QString n);
    void setadresse(QString n);
    void setdate(QDate n);
    //getters
    int getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QDate getdate();
    //fonctionalités de base relatives a l entite voyageur
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int cin,QString tel,QString nom,QString prenom,QDate dat);

QSqlQueryModel * trie_NOM();
QSqlQueryModel * trie_CIN();
//QSqlQueryModel * chercher(QString nom);
QSqlQueryModel* recherchernom(QString a);
bool recherchercin(int cin);

    voyageur();
private:
    int cin;
    QString nom,prenom,adresse;
    QDate date_naissance;
};

#endif // VOYAGEUR_H
