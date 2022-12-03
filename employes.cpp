#include "employes.h"


Employes::Employes()
{
prenom="";
nom="";
cin=0;
poste="";
salaire=0;
nb_heures_nor=0;
nb_heures_sup=0;
taches=0;
//worktime=0;

}


Employes::Employes(QString prenom,QString nom,int cin,QString poste,float salaire,int nb_heures_sup,int nb_heures_nor,int taches)
{
    this->prenom=prenom;
    this->nom=nom;
    this->cin=cin;
    this->poste=poste;
    this->salaire=salaire;
    this->nb_heures_nor=nb_heures_nor;
    this->nb_heures_sup=nb_heures_sup;
    this->taches=taches;
   // this->worktime=worktime;
}

bool Employes::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(salaire);
    QString res2=QString::number(nb_heures_nor);
    QString res3=QString::number(nb_heures_sup);
    QString res4=QString::number(taches);
    query.prepare("INSERT INTO EMPLOYES(cin,nom,prenom,poste,salaire,nb_heures_nor,nb_heures_sup,taches)"
                  "VALUES(:cin,:nom,:prenom,:poste,:salaire,:nb_heures_nor,:nb_heures_sup,:taches)");

    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire",res1);
    query.bindValue(":nb_heures_nor",res2);
    query.bindValue(":nb_heures_sup",res3);
    query.bindValue(":taches",res4);

    return query.exec();

}

QSqlQueryModel * Employes::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employes");
    return model;
}

bool Employes::supprimer(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from employes where CIN= :cin");
    query.bindValue(":cin",res);
    return query.exec();
}

bool Employes::modifier()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(salaire);
    QString res2=QString::number(nb_heures_nor);
    QString res3=QString::number(nb_heures_sup);
    QString res4=QString::number(taches);
    query.prepare("UPDATE EMPLOYES SET CIN=:cin,NOM=:nom,PRENOM=:prenom,POSTE=:poste,"
                  "SALAIRE=:salaire,NB_HEURES_NOR=:nb_heures_nor,NB_heures_SUP=:nb_heures_sup,TACHES=:taches WHERE CIN=:cin");
   query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire",res1);
    query.bindValue(":nb_heures_nor",res2);
    query.bindValue(":nb_heures_sup",res3);
    query.bindValue(":taches",res4);

    return query.exec();

}

/*void Employes::meilleursEmployes()
{
    QSqlQuery query;




}*/

void Employes::setprenom(QString prenom){this->prenom=prenom;}
void Employes::setnom(QString nom){this->nom=nom;}
void Employes::setcin(int cin){this->cin=cin;}
void Employes::setposte(QString poste){this->poste=poste;}
void Employes::setsalaire(float salaire){this->salaire=salaire;}
void Employes::setnb_heures_nor(int nb_heures_nor){this->nb_heures_nor=nb_heures_nor;}
void Employes::setnb_heures_sup(int nb_heures_sup){this->nb_heures_sup=nb_heures_sup;}
void Employes::settaches(int taches){this->taches=taches;}


QString Employes::getprenom(){return prenom;}
QString Employes::getnom(){return nom;}
int Employes::getcin(){return cin;}
QString Employes::getposte(){return poste;}
float Employes::getsalaire(){return salaire;}
int Employes::getnb_heures_nor(){return nb_heures_nor;}
int Employes::getnb_heures_sup(){return nb_heures_sup;}
int Employes::gettaches(){return taches;}
