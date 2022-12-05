#include "gestion_vol.h"
#include "ui_gestion_vol.h"
#include "vol.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QtCore>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>

gestion_vol::gestion_vol(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_vol)
{
    ui->setupUi(this);
    ui->date_vol->setValidator(new QIntValidator(0, 9999, this));
    ui->tab_vol->setModel(V.afficher());
}

gestion_vol::~gestion_vol()
{
    delete ui;
}

void gestion_vol::on_pb_ajouter_clicked()
{
     int datevol=ui->date_vol->text().toInt();
     QString nom=ui->nom_vol->text();
     QString destination=ui->destination_vol->text();
    Vol V(datevol,nom,destination);
    bool test=V.ajouter();
        if(test)
            {
              ui->tab_vol->setModel(V.afficher());

               QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("Ajout effectué\n"
                                                    "Click cancel to exit."),
                                        QMessageBox::Cancel);
               ui->tab_vol->setModel(V.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                         QObject::tr("Ajout non effectué\n"
                                                     "Click cancel to exit."),
                                         QMessageBox::Cancel);
}

void gestion_vol::on_pb_supprimer_clicked()
{
    Vol V1;
    V1.setDATEVOL(ui->vol_supp->text().toInt());
    bool test=V1.supprimer(V1.getDATEVOL());
    if(test)
        {
          ui->tab_vol->setModel(V.afficher());

           QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("supp effectué\n"
                                                "Click cancel to exit."),
                                    QMessageBox::Cancel);
           ui->tab_vol->setModel(V.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                     QObject::tr("supp non effectué\n"
                                                 "Click cancel to exit."),
                                     QMessageBox::Cancel);

}

void gestion_vol::on_pb_pdf_clicked()
{

       QPrinter printer;
       int i=4000;
       QPdfWriter pdf("Vols.pdf");
       QPainter painter(&pdf);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("Vols.pdf");
        painter.setPen(Qt::black);
        painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("D:/projet c+/logo_azure.png"));
        painter.drawText(3000,1500,"LISTE DES VOLS");
        painter.setPen(Qt::black);
        painter.drawText(300,3300,"NomVol");
        painter.drawText(2300,3300,"Date");
        painter.drawText(4300,3300,"destination");


        QSqlQuery query;
        query.prepare("SELECT * FROM  VOLS ");
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
                             QDesktopServices::openUrl(QUrl::fromLocalFile("Vols.pdf"));
                             painter.end();
                         }
                         if (reponse == QMessageBox::No)
                         {
                             painter.end();
                         }

}


void gestion_vol::on_pb_chercher_clicked()
{
        QString aux=ui->le_chercher->text();
        ui->tab_vol->setModel(V.rechercher(aux));
}

void gestion_vol::on_pb_trier_clicked()
{
     ui->tab_vol->setModel(V.tri());
}

