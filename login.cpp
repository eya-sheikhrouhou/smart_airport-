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
}

login::~login()
{
    delete ui;
}

int login::on_add_info_clicked()
{
   QMessageBox msg;

    QString id = ui->id->text() ;

    if  (id.length()<7 and (id.mid(0,3)!="DIR" or  id.mid(0,3)!="EMP" ) )
    {
                 QMessageBox::information(this,"alert","invalid ID!");



    } else {
       QSqlQuery qry;
       QString pass = ui->password->text() ;
       qry.prepare("select password from employees where password = :pass and id_emp= :id ") ;
       qry.bindValue(":id",id);
       qry.bindValue(":pass",pass);
       qry.exec() ;
       qry.next() ;
       if(qry.isValid()) {
           QMessageBox::information(this,"alert","login success !");
           main.show() ;
       }
       else{
            QMessageBox::information(this,"alert","login failed ! \n incorrect password ");

       }

    }

return 0 ;

}
