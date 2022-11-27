#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employes.h"
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QMainWindow>
#include <QtCore>
#include<QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Emp.afficher());
    QPixmap pix("D:/projet c+/logo_azure.png");
    ui->label_logo1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->label_logo2->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->label_logo3->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->label_logo4->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    ui->comboBox_restos->addItem(QIcon("D:/projet c+/projet3/Logo-McDonalds-1 (1).jpg"),"McDonalds");
    ui->comboBox_restos->addItem(QIcon(":/rec/Burger-King-2021-1.jpg"),"BurgerKing");
    ui->comboBox_restos->addItem(QIcon(":/rec/KFC logo.jpg"),"KFC");
    ui->comboBox_restos->addItem(QIcon(":/rec/kisspng-pizza-hut-kfc-restaurant-logo-5ae545214f8366.4488258615249748813257.jpg"),"PizzaHut");
    ui->comboBox_restos->addItem(QIcon(":/rec/Symbole-Starbucks (1).jpg"),"StarBucks");
    ui->comboBox_restos->addItem(QIcon(":/rec/dunkindonuts (1).png"),"DunkinDonnuts");
    ui->comboBox_restos->addItem(QIcon(":/rec/coffee-cup-logo-coffee-shop (1).jpg"),"CoffeeShop");



}

MainWindow::~MainWindow()
{
    delete ui;
}




/*void MainWindow::on_pushButton_clicked()
{
Employes e;
e.setprenom(ui->lineEdit_penom->text());
e.setnom(ui->lineEdit_nom->text());
//e.setcin(ui->lineEdit_cin->int());
e.setposte(ui->lineEdit_poste->text());
//e.setsalaire(ui->lineEdit_salaire->text());

}*/
void MainWindow::on_pushButton_ajouter_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString poste=ui->lineEdit_poste->text();
    float salaire=ui->lineEdit_salaire->text().toInt();
    int nb_heures_nor=ui->lineEdit_heuresNor->text().toInt();
    int nb_heures_sup=ui->lineEdit_heuresSup->text().toInt();
    int taches=ui->lineEdit_taches->text().toInt();
    Employes E(prenom,nom,cin,poste,salaire,nb_heures_nor,nb_heures_sup,taches);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("Ajout non effectué.\n"
                            "click cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_pushButton_3_clicked()//supprimer
{
    int cin=ui->lineEdit_cin->text().toInt();
    bool test=Emp.supprimer(cin);
    if(test)
    {
        ui->tableView->setModel(Emp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Suppresion effectuée\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "click cancel to exit."),QMessageBox::Cancel);

 }

void MainWindow::on_pushButton_modifier_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString poste=ui->lineEdit_poste->text();
    float salaire=ui->lineEdit_salaire->text().toInt();
    int nb_heures_nor=ui->lineEdit_heuresNor->text().toInt();
    int nb_heures_sup=ui->lineEdit_heuresSup->text().toInt();
    int taches=ui->lineEdit_taches->text().toInt();
    Employes E(prenom,nom,cin,poste,salaire,nb_heures_nor,nb_heures_sup,taches);
    bool test=E.modifier();
    if(test)
    {
        ui->tableView->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("modification effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("modification non effectué.\n"
                            "click cancel to exit."),QMessageBox::Cancel);

}




void MainWindow::on_pushButton_carte_clicked()
{
    QSqlQuery query;
    int cin=ui->cin_r->text().toInt();
    query.prepare("SELECT cin,salaire FROM  employes   WHERE  cin = :CIN   ");
    query.bindValue(":CIN",cin);

    if(query.exec())
    {
        if(( ui->comboBox_restos->currentText()=="McDonalds") ||( ui->comboBox_restos->currentText()=="BurgerKing") ||
                ( ui->comboBox_restos->currentText()=="KFC")||( ui->comboBox_restos->currentText()=="PizzaHot"))
        {
            query.prepare("SELECT salaire FROM employes WHERE cin:=CIN");
            int s=query.value(0).toInt();
            if (s<1000)
            {

                QMessageBox::information(nullptr,QObject::tr("carte resto"),
                        QObject::tr("reduction de 10% sur chaque commande\n"
                                    "click cancel to exit."),QMessageBox::Cancel);
            }
            else if(s>=1000)
            {
                QMessageBox::critical(nullptr,QObject::tr("carte resto"),
                        QObject::tr("reduction de 5% sur chaque commande.\n"
                                    "click cancel to exit."),QMessageBox::Cancel);
            }


        }
        else
        {
            query.prepare("SELECT salaire FROM employes WHERE cin:=CIN");
            int s=query.value(0).toInt();
            if (s<1000)
            {

                QMessageBox::information(nullptr,QObject::tr("carte resto"),
                        QObject::tr("reduction de 15% sur chaque commande\n"
                                    "click cancel to exit."),QMessageBox::Cancel);
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("carte resto"),
                        QObject::tr("reduction de 10% sur chaque commande.\n"
                                    "click cancel to exit."),QMessageBox::Cancel);
        }


        }

    }




void MainWindow::on_pushButton_search_clicked()
{
    QSqlQuery query;
    int cin=ui->cin_r->text().toInt();
    query.prepare("SELECT cin,nom,prenom,poste,salaire,nb_heures_nor,nb_heures_sup,taches FROM  employes   WHERE  cin = :CIN   ");
    query.bindValue(":CIN",cin);
    QSqlQueryModel * model=new QSqlQueryModel();

    if(query.exec())
    {
        query.next();
        model->setQuery(query);
        ui->tableView->setModel(model);
    }

}





void MainWindow::on_pushButton_clicked()//pdf
{

       QPrinter printer;
       int i=4000;
       QPdfWriter pdf("Employes.pdf");
       QPainter painter(&pdf);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("Employes.pdf");
        painter.setPen(Qt::black);
        painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("D:/projet c+/logo_azure.png"));
        painter.drawText(3000,1500,"LISTE DES EMPLOYES");
        painter.setPen(Qt::black);
        painter.drawText(300,3300,"cin");
        painter.drawText(2300,3300,"nom");
        painter.drawText(4300,3300,"prenom");
        painter.drawText(6300,3300,"poste");
        painter.drawText(8300,3300,"salaire");


        QSqlQuery query;
        query.prepare("SELECT * FROM  employes ");
        query.exec();
        while (query.next())
                         {
                             painter.drawText(300,i,query.value(0).toString());
                             painter.drawText(2300,i,query.value(1).toString());
                             painter.drawText(4300,i,query.value(2).toString());
                             painter.drawText(6300,i,query.value(3).toString());
                             painter.drawText(8300,i,query.value(4).toString());
                             i = i +500;
                         }
        int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                         if (reponse == QMessageBox::Yes)
                         {
                             QDesktopServices::openUrl(QUrl::fromLocalFile("Employes.pdf"));
                             painter.end();
                         }
                         if (reponse == QMessageBox::No)
                         {
                             painter.end();
                         }



}

void MainWindow::on_pushButton_search_tri_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT cin,nom,prenom,poste,salaire,nb_heures_nor,nb_heures_sup,taches FROM  employes ORDER BY cin ASC  ");
    QSqlQueryModel * model=new QSqlQueryModel();

    if(query.exec())
    {
        query.next();
        model->setQuery(query);
        ui->tableView->setModel(model);
    }

}


