#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bagage.h"
#include"connection.h"
#include<QtGui>
#include<QtCore>
#include <QSqlQuery>
#include<QDebug>
#include<iostream>
#include<QIntValidator>
#include <QtCore>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQueryModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/azizo/OneDrive/Bureau/aziz_repo/gestion_bagage/307841663_519072713563574_557044734057287878_n.png");
    ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
     ui->tabWidget->setCurrentIndex(0)  ;
     ui->id_search_info->setValidator(new QIntValidator(0,1000000,this));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_id_search_button_clicked()
{   using namespace std ;

   int  CIN=ui->id_search_info->text().toInt();
     QString d=QString::number(CIN);
   printf("\n\n\n%d\n\n",CIN);
     QMessageBox msg;
    QSqlQuery query , query1 ;
    query.prepare("SELECT aziz.voyageurs.nom, aziz.voyageurs.prenom FROM    aziz.voyageurs WHERE  aziz.voyageurs.cin = :CIN   ");
    query1.prepare("SELECT num_bg, poids ,frais  FROM  bagages WHERE cin = :CIN ")  ;
    query1.bindValue(":CIN",d) ;
    query.bindValue(":CIN",d);
    query1.exec()  ;
    if (query.exec()) {
             printf("yes");
             ui->name_info->setText("0") ;
             ui->pname_info->setText("0") ;
             ui->NUM_BG_info->setText("0") ;
             ui->poids_info->setText("0") ;
             ui->frais_info->setText("0") ;
             query.next() ;
             query1.next();

            if ( query.isValid()==false  ) {   QMessageBox::information(this,"alert","invalid CIN !"); }
                    else {
            //****************add****************//
            ui->cin_add->setText(d);
            ui->poids_add->setText(query1.value(2).toString()) ;
            ui->name_add->setText(query.value(0).toString()) ;
            //****************info******************//
            ui->name_info->setText(query.value(0).toString()) ;
            ui->pname_info->setText(query.value(1).toString()) ;
            ui->NUM_BG_info->setText(query1.value(0).toString()) ;
            ui->poids_info->setText(query1.value(1).toString()) ;
            ui->frais_info->setText(query1.value(2).toString()) ;
            //*************results******************//
            ui->cin_res->setText(d) ;
            ui->name_res->setText(query.value(0).toString()) ;
            ui->pname_res->setText(query.value(1).toString()) ;
            ui->num_bg_res->setText(query1.value(0).toString()) ;
            ui->poids_res->setText(query1.value(1).toString()) ;
            ui->frais_res->setText(query1.value(2).toString()) ;
            //***************delete********************//
            ui->poids_supp->setText(query1.value(3).toString()) ;
            ui->cin_sup->setText(d) ;
            ui->frais_supp->setText(query1.value(2).toString()) ;
            //*************ajout***********//
            ui->cin_ajout->setText(d) ;
            if ( query1.isValid()==false  ) {   QMessageBox::information(this,"alert","pas de bagage pour ce voyageur ! "); }
                 }
    }
    else{
     qDebug() <<"ERROR = "  ;
     QMessageBox::information(this,"alert","invalid querry !");
    }
}


void MainWindow::on_supp_info_clicked()
{
    ui->tabWidget->setCurrentIndex(3)  ;

    //goto suppression tab
}



void MainWindow::on_add_info_clicked()
{   int nbg= ui->NUM_BG_info->text().toInt();
    if(nbg){
    ui->tabWidget->setCurrentIndex(2)  ;
    //goto modify tab
    }
    else {
    ui->tabWidget->setCurrentIndex(1)  ;
    //goto add tab
    }

}

void MainWindow::on_confirm_ajout_clicked()
{
     ui->tabWidget->setCurrentIndex(4)  ;

     // display final infos..
}

void MainWindow::on_modify_poids_clicked()
{    QString cin= ui->cin_add->text();

     qDebug() <<cin<<endl ;

float h=ui->poids_add_2->currentIndex() ;
if(h==0 ){

  QMessageBox::information(this,"alert","Veuillez sélectioner le poids");  }
else{
    QString P=ui->poids_add_2->currentText()   ;
  // ***************************UPDATE SQL**********************//
 QSqlQuery query ;
  query.prepare(" UPDATE aziz.bagages set POIDS = :P where CIN= :CIN ");
  query.bindValue(":P",P);
   query.bindValue(":CIN",cin);
   query.exec();
   ui->poids_res->setText(P) ;
   ui->poids_add->setText(P) ;
   ui->poids_supp->setText(P) ;
  QMessageBox::information(this,"alert","poids ajoutée! cin:",cin);}
}

void MainWindow::on_add_poids_sup_clicked()
{ QSqlQuery query1 ,query;
    QString cin ;
    cin= ui->cin_add->text() ;
    if(ui->poidsSup_add->currentIndex()==0 ){
        QMessageBox::information(this,"alert","Veuillez sélectioner le poids a ajouter");  }
    else{
        QString calcf=ui->poidsSup_add->currentText();
        calcf.toInt() ;
        query1.prepare("SELECT numero from voyager where cin= :CIN ") ;
        query1.bindValue(":CIN",cin) ;
       if ( query1.exec() ) {
        query1.next() ;
        int nb;
        nb=query1.value(0).toInt() ;
        qDebug() << "nb is : "<<nb <<endl ;
        query.prepare("SELECT COUNT(*) from voyager where numero= :NB ") ;
        query.bindValue(":NB",nb) ;
        query.exec();
        query.next();
        float res=query.value(0).toInt()  ;
        qDebug()<<"dd;"<<40+60*(res/200) <<endl;
        ui->calcul_frais->display(40+60*(res/200) );
         // ***************************UPDATE SQL**********************//
        query.prepare(" UPDATE aziz.bagages set POIDS_SUP = :P where CIN= :CIN ");
        QString p=ui->poids_add_2->currentText()    ;
        query.bindValue(":P",p);
         query.bindValue(":CIN",cin);
         QMessageBox::information(this,"alert","working on in!");
            float pnt= p.toUInt() ;
         ui->frais_res->setText(QString::number((40+60*(res/200))*pnt) )  ;
}
    }
}

void MainWindow::on_ajouter_clicked()
{   QString cin= ui->cin_ajout->text();
    QString idbg= ui->NUM_BG_ajout->text() ;
    QString poids =ui->poids_ajout->text() ;
    QSqlQuery query ;
    qDebug() <<"cin: "<<cin <<"idbg:  "<<  idbg<<"poids : "<<poids<<endl ;
    query.prepare("INSERT INTO aziz.bagages (NUM_BG, POIDS,CIN) VALUES (:idbg, :poids, :CIN)");
    query.bindValue(":idbg",idbg);
    query.bindValue(":poids",poids);
    query.bindValue(":CIN",cin);
    ui->num_bg_res->setText(idbg) ;
    ui->poids_res->setText(poids) ;
    query.exec();

    QMessageBox::information(this,"alert","information ajoutée avec succèes ");

    ui->tabWidget->setCurrentIndex(4)  ;


}

void MainWindow::on_supp_clicked()
{ QString cin= ui->id_search_info->text() ;
    QSqlQuery query ;

     query.prepare("DELETE FROM aziz.bagages WHERE aziz.bagages.cin = :CIN" );
     query.bindValue(":CIN",cin);
     query.exec();
      ui->tabWidget->setCurrentIndex(4)  ;

}





void MainWindow::on_pdf_clicked()
{QPrinter printer;
    QString cin =ui->cin_res->text() ;
   QString name =  ui->name_res->text() ;
    QString pname= ui->pname_res->text() ;
    QString nmbg = ui->num_bg_res->text() ;
  QString poids =   ui->poids_res->text()  ;
   QString psup=  ui->poids_ajoute_res->text() ;
    QString frais = ui->frais_res->text() ;
     QPdfWriter pdf("Bagages.pdf");

                  QPainter painter(&pdf);

                  int i = 4000;
                  painter.setPen(Qt::darkGray);
                  painter.setFont(QFont("Helvetica", 30));
                  painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/azizo/Downloads/307539691_606289314485611_1205161165924749029_n.png"));
                  painter.drawText(3000,1500,"LISTES DES BAGAGES");
                  painter.setPen(Qt::darkGray);
                  painter.setFont(QFont("Helvetica", 50));
                  painter.drawRect(2700,200,6300,2600);
                  painter.drawRect(0,3000,9600,500);
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Helvetica", 9));
                  painter.drawText(300,3300,"cin");
                  painter.drawText(2300,3300,"nom");
                  painter.drawText(4300,3300,"num_bg");
                  painter.drawText(6300,3300,"poids");
                  painter.drawText(8300,3300,"poids_sup");
                  painter.drawText(10300,3300,"frais");

                  QSqlQuery query , query1;
                  query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                  time_t tt;
                  struct tm* ti;
                  time(&tt);
                  ti=localtime(&tt);
                  asctime(ti);
                  painter.drawText(500,300, asctime(ti));
                  query.prepare("select * from bagages");
                  query.exec();
                  query1.prepare("select nom ,cin from VOYAGEURS");
                  query1.exec();
                  while (query.next() and query1.next() )
                  {
                      painter.drawText(300,i,query1.value(1).toString());
                      painter.drawText(2300,i,query1.value(0).toString());
                      painter.drawText(4300,i,query.value(0).toString());
                      painter.drawText(6300,i,query.value(2).toString());
                      painter.drawText(8300,i,query.value(1).toString()) ;
                      painter.drawText(10300,i,query.value(4).toString()) ;
                     // painter.drawText(10300,i,query.value(5).toString());
                      i = i +500;
                  }

                  int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                  if (reponse == QMessageBox::Yes)
                  {
                      QDesktopServices::openUrl(QUrl::fromLocalFile("Bagages.pdf"));
                      painter.end();
                  }
                  if (reponse == QMessageBox::No)
                  {
                      painter.end();
                  }

}

void MainWindow::on_tri_clicked()
{

QSqlQuery query;
query.prepare("SELECT * FROM  bagages ORDER BY cin ASC  ");
QSqlQueryModel * model=new QSqlQueryModel();

if(query.exec()){
query.next();
model->setQuery(query);
ui->tableView->setModel(model);
}

}



void MainWindow::on_affichetout_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM  bagages  ");
    QSqlQueryModel * model=new QSqlQueryModel();

    if(query.exec()){
    query.next();
    model->setQuery(query);
    ui->tableView->setModel(model);
    }
}


