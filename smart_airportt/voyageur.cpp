#include "voyageur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>


voyageur::voyageur()
{nom="";
 prenom="";
 adresse="";
 cin=0;

}
voyageur::voyageur(int ci,QString no,QString pre,QString adre)
{
    nom=no;
    cin=ci;
    prenom=pre;
    adresse=adre;
   // date_naissance=dat;

}
void voyageur::setcin(int n){cin=n;}

void voyageur::setnom(QString n){nom=n;}
void voyageur::setprenom(QString n){prenom=n;}
void voyageur::setadresse(QString n){adresse=n;}
void voyageur::setdate(QDate n){date_naissance=n;}


QString voyageur::getnom(){return nom;}
QString voyageur::getprenom(){return prenom ;}
QString voyageur::getadresse(){return adresse;};
QDate voyageur:: getdate(){return date_naissance ;}
int voyageur::getcin(){return cin;}

bool voyageur::ajouter()
{//bool test=false;

  QSqlQuery query;

  QString cin_string=QString::number(cin);             //c quoi number heddhy mafhemthechh
        query.prepare("INSERT INTO VOYAGEURS (cin,nom,prenom,adresse) "
                      "VALUES (:cin, :nom, :prenom ,:adresse)");
        query.bindValue(":cin", cin_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":adresse", adresse);
       return query.exec();


}
bool voyageur::supprimer(int cin)
{


   QSqlQuery query;
   QString res=QString::number(cin);
   query.prepare("Delete from voyageurs where cin=:cin");
   query.bindValue(":cin",res);
   return query.exec();


}

QSqlQueryModel * voyageur::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM VOYAGEURS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));

     return model;
}


bool voyageur::modifier(int cin,QString adresse,QString nom,QString prenom)
{
    QSqlQuery query;
    query.prepare("update system.voyageurs set adresse=:adresse,nom=:nom,prenom=:prenom where cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":tel", adresse);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
    return    query.exec();
}
/*
QSqlQueryModel* voyageur::chercher(int cin)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= cin;
 model->setQuery("select * from system.voyageurs where cin='"+res+"'");
return model;
}

*/









