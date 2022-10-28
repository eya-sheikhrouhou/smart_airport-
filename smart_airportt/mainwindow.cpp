#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voyageur.h"
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include<QValidator>
#include<QSqlQueryModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_voyageur->setModel(Etmp.afficher()); //affichage

    QPixmap pix("C:/Users/eya sheikhrouhou/Documents/smart_airport/Screenshot 2022-09-20 202443.png");
  ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
  ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_upLeft_clicked()
{
   // voyageur v;
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
  //  QDate date_naissance=ui->dateEdit-;

   /*  v.setcin(ui->lineEdit_cin->text().toUInt());
       v.setnom(ui->lineEdit_nom->text());
       v.setprenom(ui->lineEdit_prenom->text());
       v.setadresse(ui->lineEdit_adresse->text());
       v.setdate(ui->dateEdit->date());

       //QString nom=v.getnom();
   //    QMessageBox::warning(this,"vous avez enregistrer ","  nom:"+ nom +"  prenom:"
                    //        +v.getprenom()+"  adresse:"+v.getadresse()+"  date:"+v.getdate().toString("yyyy/dd/MM"));

         */
    voyageur v(cin,nom,prenom,adresse);
       bool test=v.ajouter();
       if(test)
       {  //mise a jour
           ui->table_voyageur->setModel(Etmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout  effectué \n ""click cancel to exist."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("ajout non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);

}





void MainWindow::on_pushButton_supprimer_clicked()
{
    int cin=ui->lineEdit_soc->text().toInt();
    bool test=Etmp.supprimer(cin);
    if(test)
    {    //mise ajour
        ui->table_voyageur->setModel(Etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué \n ""click cancel to exist."),QMessageBox::Cancel);

    }
    else  QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("suppression non effectué \n ""click cancel to exist."),QMessageBox::Cancel);
}
/*
void MainWindow::on_pushButton_modifier_clicked()
{ QSqlQuery query;

  int cin =ui->lineEdit_soc_2->text().toInt();
     QString  res= ui->lineEdit_modifier->text();
    if(ui->comboBox->currentText()=="nom")
    {

         query.prepare("select :nom from voyageurs where cin=:cin");

         query.bindValue(":nom",res);
          ui->table_voyageur->setModel(Etmp.afficher());



    }
}


*/



void MainWindow::on_pushButton_modifier_clicked()
{ //int cin =ui->lineEdit_soc_2->text().toInt();

   int cin=ui->lineEdit_soc_2->text().toInt();
   QString nom=ui->lineEdit_cin->text();
   QString prenom=ui->lineEdit_prenom->text();
   QString adresse=ui->lineEdit_adresse->text();
 voyageur v;
 v.chercher(cin);



  bool test=v.modifier(cin,adresse,nom,prenom);
  if(test)
  {  //mise a jour
      ui->table_voyageur->setModel(Etmp.afficher());
      QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification  effectué \n ""click cancel to exist."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("modification non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);






}
