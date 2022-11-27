#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employes
{
public:
    //constructeurs
    Employes();
    Employes(QString,QString,int,QString,float,int,int,int);

    //setters
    void setprenom(QString n);
    void setnom(QString n);
    void setcin(int n);
    void setposte(QString n);
    void setsalaire(float n);
    void setnb_heures_nor(int n);
    void setnb_heures_sup(int n);
    void settaches(int n);


    //getters
    QString getprenom();
    QString getnom();
    int getcin();
    QString getposte();
    float getsalaire();
    int getnb_heures_nor();
    int getnb_heures_sup();
    int gettaches();
  //  float getworktimes();

    //fonctionnalités de base relatives a l'entité employes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    void meilleursEmployes();

private:
    QString prenom,nom,poste;
    float salaire;
    int nb_heures_sup,nb_heures_nor,taches,cin;
};

#endif // EMPLOYES_H
