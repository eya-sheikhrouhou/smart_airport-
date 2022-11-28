#include "login.h"
#include "ui_login.h"
#include<QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

login::~login()
{
    delete ui;
}

int login::on_add_info_clicked()
{
   QMessageBox msg;
    QString id = ui->id->text() ;
    QString data ;
      QByteArray b ;
    if  (id.length()<7 and (id.mid(0,3)!="DIR" or  id.mid(0,3)!="EMP" ) )
    {

                    data = "INVALID ID"  ;
                    b= data.toUtf8() ;
                    A.write_to_arduino(b);
                     QMessageBox::information(this,"alert","invalid ID!");


    } else {
       QSqlQuery qry;
       QString pass = ui->password->text() ;
       qry.prepare("select password from employes where password = :pass and id_emp= :id ") ;
       qry.bindValue(":id",id);
       qry.bindValue(":pass",pass);
       qry.exec() ;
       qry.next() ;
       if(qry.isValid()) {

              data = "login success ! "  ;


              data="welcome " ;
              qry.prepare("select nom from employes where id_emp= :id ") ;
              qry.bindValue(":id",id);
              qry.exec() ;
              qry.next() ;
              data+=qry.value(0).toString() ;
              b= data.toUtf8() ;
               A.write_to_arduino(b);
                QMessageBox::information(this,"alert","login success !");


          if(id.mid(0,3)=="DIR" ){
              mn.show();
              this->hide() ;
          }
          else {
              mn.hide_button() ;
              mn.show() ;
              this->hide() ;
          }
       }
       else{

           data = "INCORRECT PASSWORD !"  ;
            b= data.toUtf8() ;
             A.write_to_arduino(b);
             QMessageBox::information(this,"alert","login failed ! \n incorrect password ");

       }

    }

return 0 ;

}


