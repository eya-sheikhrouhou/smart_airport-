#include "vol.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Vol::Vol()
{
    datevol=0;nom=" ";destination=" ";
}
Vol::Vol(int datevol,QString nom,QString destination)
{this->datevol=datevol; this-> nom=nom;this->destination=destination;}
QString Vol::getNom(){return nom;}
int Vol::getDATEVOL(){return datevol;}

QString Vol::getDestination(){return destination;}


void Vol::setNom(QString nom){this->nom=nom;}
void Vol::setDATEVOL(int datevol){this->datevol=datevol;}
void Vol::setDestination(QString destination){this->destination=destination;}
bool Vol::ajouter()
{
    QSqlQuery query;
    QString datevol_string= QString::number(datevol);
         query.prepare("INSERT INTO VOLS  (nom, datevol, destination) "
                       "VALUES (:nom, :datevol, :destination)");
         query.bindValue(0, nom);
         query.bindValue(1, datevol_string);

         query.bindValue(2, destination);
         query.exec();

}
bool Vol::supprimer(int datevol)
{
    QSqlQuery query;
    QString datevol_string= QString::number(datevol);
         query.prepare("Delete from VOLS where datevol=:datevol");
         query.bindValue(":datevol", datevol_string);
         query.exec();
}
QSqlQueryModel* Vol::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM VOLS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_vol"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination "));
    return  model;
}


 QSqlQueryModel * Vol::rechercher ( QString aux)

 {
     QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("select * from VOLS where ((NOM||DATEVOL||DESTINATION) LIKE '%"+aux+"%')");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEVOL"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));


     return model;

 }
 QSqlQueryModel * Vol::tri()
  {
      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("select * from  VOLS ORDER BY DATEVOL");

      model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEVOL"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
 return model;
  }
