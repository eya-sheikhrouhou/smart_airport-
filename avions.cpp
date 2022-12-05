#include "avions.h"
#include "ui_avions.h"
#include "Avion.h"
#include"connection.h"
#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

#include <QtCore>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>

#include <QDesktopServices>
#include <QPushButton>
#include <QUrl>


avions::avions(QDialog *parent)
    : QDialog(parent)
    ,

    ui(new Ui::avions)
{
    ui->setupUi(this);
    ui->tab_avions->setModel(A.afficher());

    QPixmap pix("C:/Users/Zoghlami Dhirar/OneDrive/Bureau/integ/smart_airport-");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/Zoghlami Dhirar/OneDrive/Bureau/integ/smart_airport-");
    ui->label_pic1->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix2("C:/Users/Zoghlami Dhirar/OneDrive/Bureau/integ/smart_airport-");
    ui->label_pic2->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //Arduino
    int ret=Ar.connect_arduino();        // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).

    //stat
    QLineSeries *series = new QLineSeries();

    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(7,4);
    series->append(10,5);

    *series << QPointF(11,1) << QPointF(13,3) << QPointF(17,6) << QPointF(18,3) << QPointF(20,2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Statistiques des vols");

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);


    QPieSeries *series1 = new QPieSeries();

    series1->append("Tunisair",80);
    series1->append("QatarAirlines",70);
    series1->append("Nouvelair",50);
    series1->append("DeltaAirlines",40);
    series1->append("TurkishAirlines",30);

    QChart *chart1 = new QChart();
    chart1->legend()->hide();
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setTitle("Airlines");

    QChartView *chartview1 = new QChartView(chart1);
    chartview1->setParent(ui->horizontalFrame_2);


}

avions::~avions()
{
    delete ui;
}

void avions::update_label()
{
    data=Ar.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void avions::on_pb_ajouter_clicked()
{
    QString id=ui->lineEdit_Id->text();
    QString airline=ui->lineEdit_Airline->text();
    QString date=ui->dateEdit->date().toString("dd-MM-yyyy");
    int num=ui->lineEdit_Num_flight->text().toInt();

    Avion A(id,airline,date,num);

    bool test=A.ajouter();

    if(test)
    {
       ui->tab_avions->setModel(A.afficher());
       Ar.write_to_arduino(("2"));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void avions::on_pb_modifier_clicked()
{   avions av ;

    QString id=ui->lineEdit_Id->text();
    QString airline=ui->lineEdit_Airline->text();
    QString date=ui->dateEdit->date().toString("dd-MM-yyyy");
    int num=ui->lineEdit_Num_flight->text().toInt();

    Avion A(id,airline,date,num);

    bool test=A.modifier();

    if(test)
    {
       ui->tab_avions->setModel(A.afficher());
       Ar.write_to_arduino(("3"));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void avions::on_pb_supprimer_clicked()
{
    int id=ui->lineEdit_supprimer->text().toInt();

    bool test=A.supprimer(id);

    if(test)
    {
        ui->tab_avions->setModel(A.afficher());
        Ar.write_to_arduino(("4"));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_avions->setModel(A.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


int avions::on_pb_pdf_clicked()
{
                 QPdfWriter pdf("Liste.pdf");

                 QPainter painter(&pdf);

                 int i = 4000;
                 painter.setPen(Qt::darkGray);
                 painter.setFont(QFont("Helvetica", 30));
                 painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/Zoghlami Dhirar/OneDrive/Bureau/ProjetCpp/Entite_Avions/Azure.png"));
                 painter.drawText(3000,1500,"LISTE DES AVIONS");
                 painter.setPen(Qt::darkGray);
                 painter.setFont(QFont("Helvetica", 50));
                 painter.drawRect(2700,200,6300,2600);
                 painter.drawRect(0,3000,9600,500);
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Helvetica", 9));
                 painter.drawText(300,3300,"ID");
                 painter.drawText(2300,3300,"Airline");
                 painter.drawText(4300,3300,"R_F_DATE");
                 painter.drawText(6000,3300,"Num_Flight");

                 QSqlQuery query;
                 query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                 time_t tt;
                 struct tm* ti;
                 time(&tt);
                 ti=localtime(&tt);
                 asctime(ti);
                 painter.drawText(500,300, asctime(ti));
                 query.prepare("select * from AVIONS");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(300,i,query.value(0).toString());
                     painter.drawText(2300,i,query.value(1).toString());
                     painter.drawText(4300,i,query.value(2).toString());
                     painter.drawText(6300,i,query.value(3).toString());

                     i = i +500;
                 }

                 int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                 if (reponse == QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl::fromLocalFile("Liste.pdf"));
                     painter.end();
                 }
                 if (reponse == QMessageBox::No)
                 {
                     painter.end();
                 }
}

void avions::on_pb_chercher_clicked()
{
    QString aux=ui->lineEdit_supprimer->text();

    ui->tab_avions->setModel(A.rechercher(aux));
    Ar.write_to_arduino(("5"));
}

void avions::on_pb_trier_clicked()
{
  QString choix=ui->comboBox->currentText();
  if (choix == "Id")
  {
      ui->tab_avions->setModel(A.tri());
      Ar.write_to_arduino(("6"));
  }
  else ui->tab_avions->setModel(A.tri1());

}

void   avions::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    //ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}


void avions::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("zoghlami.dhirar.10@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    if( !files.isEmpty() )
        smtp->sendMail("zoghlami.dhirar.10@gmail.com", ui->rcpt->text() ,ui->subject->text(), ui->msg->toPlainText(), files );
    else
        smtp->sendMail("zoghlami.dhirar.10@gmail.com", ui->rcpt->text() ,ui->subject->text(),ui->msg->toPlainText());
}

void  avions::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void avions::on_verif_clicked()
{
    int nbr= ui->nbr_perso->text().toInt();

       if(nbr > 20)
        {
             Ar.write_to_arduino(("1"));
        }
       else if(nbr <= 20)
        {
             Ar.write_to_arduino(("0"));
         }

}

void avions::on_tester_clicked()
{
    QString aux1=A.tester();

    QString str(aux1);
    QByteArray br = str.toUtf8();

    Ar.write_to_arduino(br);


}

