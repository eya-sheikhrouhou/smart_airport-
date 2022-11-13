#include "voyageur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QMessageBox>





voyageur::voyageur()
{nom="";
 prenom="";
 adresse="";
 cin=0;

}
voyageur::voyageur(int ci,QString no,QString pre,QString adre,QDate dat)
{
    nom=no;
    cin=ci;
    prenom=pre;
    adresse=adre;
    date_naissance=dat;

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

  QString cin_string=QString::number(cin);      //transformer le cin de int en string
        //Prepares the SQL query query for execution. Returns true if the query is prepared successfully; otherwise returns false.
        query.prepare("INSERT INTO VOYAGEURS (cin,nom,prenom,adresse,date_naissance) "
                      "VALUES (:cin, :nom, :prenom ,:adresse,:date_naissance)");

       //Set the placeholder to be bound to value val in the prepared statement.

        query.bindValue(":cin", cin_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":adresse", adresse);
         query.bindValue(":date_naissance", date_naissance);
       return query.exec();


}


bool voyageur::supprimer(int cin)
{


    QSqlQuery query;
        QString cin_string=QString::number(cin);
        if(query.exec("select * from voyageurs where cin='"+cin_string+"'"))
        { int count=0;
            while(query.next())
                count++;
            if (count!=0)
           {
              query.prepare(" Delete from voyageurs where cin=:cin");
              query.bindValue(":cin", cin_string);
               return query.exec();
            }

 else    return false;

      }


}


QSqlQueryModel * voyageur::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM VOYAGEURS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_naissance"));

     return model;
}

bool voyageur::modifier(int cin,QString adresse,QString nom,QString prenom,QDate date_naissance)
{
    QSqlQuery query;
    query.prepare("update  VOYAGEURS set adresse=:adresse,nom=:nom,prenom=:prenom ,date_naissance=:date_naissance   where cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":adresse", adresse);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
       query.bindValue(":date_naissance", date_naissance);
    return    query.exec();
}

/*
bool voyageur::modifier(int cin,QString adresse,QString nom,QString prenom,QDate date_naissance)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);

    if(query.exec("select * from voyageurs where cin='"+cin_string+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count!=0)
       {
            query.bindValue(":cin",cin);
          query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
            query.bindValue(":adresse",adresse);
             query.bindValue(":date_naissance", date_naissance);
            // return query.exec();
          }
          else
        {
              QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                            QObject::tr("l'identifiant n'existe pas .\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
        }
          }
    return query.exec();
*/

QSqlQueryModel * voyageur::trie_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM VOYAGEURS ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_naissance"));


    return model;
}

QSqlQueryModel * voyageur::trie_CIN()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM VOYAGEURS ORDER BY cin");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_naissance"));


    return model;
}




QSqlQueryModel* voyageur::recherchernom(QString nom)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from VOYAGEURS where nom ='"+nom+"' ");
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));
            return model;
    }

bool voyageur::recherchercin( int cin)
    {
    QSqlQuery query;
        query.prepare("select * from VOYAGEURS where cin = :cin;");
        query.bindValue(":cin", cin);
        return query.exec();

    }
//juste njareb fel git




int voyageur::statistique(QString adresse)
{
    QSqlQuery query;
    query.prepare("select count(*) from voyageurs where adresse=:adresse ");
    query.bindValue(":adresse",adresse);
    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt() ;
                        //qDebug() << "count=" << count ;
                        return count;

                    }

    return count;

}
