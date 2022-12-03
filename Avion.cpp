#include "Avion.h"
//#include "ui_avions.h"
#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Avion::Avion()
{

}

Avion::Avion(QString id,QString airline,QString R_F_Date ,int num_flight)
{
    this->id=id;
    this->airline=airline;
    this->R_F_Date=R_F_Date;
    this->num_flight=num_flight;
}

QString Avion::get_id() {return id;}
QString Avion::get_airline(){return airline;}
QString Avion::get_R_F_Date(){return R_F_Date; }

void Avion::set_id(QString id){this->id=id;}
void Avion::set_airline(QString airline){this->airline=airline;}
void Avion::set_R_F_Date(QString R_F_Date){this->R_F_Date=R_F_Date;}

QSqlQueryModel * Avion::afficher()
{
      QSqlQueryModel * model=new QSqlQueryModel();


      model->setQuery("select * from AVIONS ");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("AIRLINE"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("R_F_DATE"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_FLIGHT"));

      return model;
}


bool Avion::ajouter()
{

    QSqlQuery query;
    //QString res=QString::number(id);


    query.prepare("INSERT INTO AVIONS (ID, AIRLINE, R_F_DATE, NUM_FLIGHT)"
                  "VALUES (:ID, :AIRLINE, :R_F_DATE, :NUM_FLIGHT)");

    query.bindValue(":ID", id);
    query.bindValue(":AIRLINE", airline);
    query.bindValue(":R_F_DATE", R_F_Date);
    query.bindValue(":NUM_FLIGHT", num_flight);


 return query.exec();
}

bool Avion::modifier()
{
    QSqlQuery query;
    //QString res=QString::number(id);

     query.prepare("UPDATE AVIONS SET  ID=:id ,AIRLINE=:airline,R_F_DATE=:R_F_Date, NUM_FLIGHT=:num_flight WHERE ID=:id");

     query.bindValue(":id",id);
     query.bindValue(":airline",airline);
     query.bindValue(":R_F_Date",R_F_Date);
     query.bindValue(":num_flight",num_flight);


 return query.exec();
}

bool Avion::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Delete from AVIONS where ID= :id");
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Avion::tri()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  AVIONS ORDER BY ID");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("AIRLINE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("R_F_DATE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_FLIGHT"));

return model;
 }

QSqlQueryModel * Avion::tri1()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  AVIONS ORDER BY NUM_FLIGHT");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("AIRLINE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("R_F_DATE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_FLIGHT"));

return model;
 }


 QSqlQueryModel * Avion::rechercher ( QString aux)

 {
     QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("select * from AVIONS where ((ID||AIRLINE||R_F_DATE||NUM_FLIGHT) LIKE '%"+aux+"%')");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("AIRLINE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("R_F_DATE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_FLIGHT"));

     return model;

 }

QString Avion::tester()
{
    QSqlQuery query;

    query.prepare("Select AIRLINE from AVIONS");
    query.exec() ;
    query.next() ;
    return  query.value(0).toString();


}


