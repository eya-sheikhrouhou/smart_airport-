#include "gestion_voyageur.h"
//#include "ui_mainwindow.h"
//#include "ui_gestion_voyageur.h"

#include"voyageur.h"
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include<QValidator>
#include<QSqlQueryModel>
#include"connection.h"
#include<QDebug>
//teb3in pdf
#include <QtCore>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include<QImage>
#include"exportexcelobject.h"
#include<QDateEdit>
#include <QDate>




// ******************



gestion_voyageur::gestion_voyageur(QDialog *parent)
    :QDialog(parent)
    ,

     ui(new Ui::gestion_voyageur)
{
    ui->setupUi(this);
    ui->table_voyageur->setModel(Etmp.afficher()); //affichage

    QPixmap pix("C:/Users/Zoghlami Dhirar/OneDrive/Bureau/smart_airport--integ_eya_aziz");
    ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));


  ///statistiques***************************************************************************

  int cin=0;
        QString nom="";
        QString prenom="";
        QString adresse="";
        QDate date_naissance;
        QString code="";


      voyageur m(cin,nom,prenom,adresse,date_naissance,code);






                QPieSeries *series = new QPieSeries();
                series->setHoleSize(0.35);


                int nbr=m.statistique("Tunis");
                int nbrr=m.statistique("Sfax");
                int nbrrr=m.statistique("Sousse");
                int nb=m.statistique("Siliana");
                int total=nbr+nbrr+nbrrr+nb;

                QString a=QString("Tunis "+QString::number((nbr*100)/total,'f',2)+"%" );
                QString b=QString("Sfax "+QString::number((nbrr*100)/total,'f',2)+"%" );
                QString c=QString("Sousse "+QString::number((nbrrr*100)/total,'f',2)+"%" );
                QString d=QString("Siliana "+QString::number((nb*100)/total,'f',2)+"%" );
                QPieSlice *slice = series->append(d,nb);
                slice->setExploded();
                slice->setLabelVisible();
                series->append(a,nbr);
                series->append(b, nbrr);
                series->append(c, nbrrr);

                QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setAnimationOptions(QChart::SeriesAnimations);
                chart->setTitle("statistiques parlieu");
                chart->setTheme(QChart::ChartThemeBlueIcy);


                QChartView *chartview = new QChartView(chart);
                chartview->setRenderHint(QPainter::Antialiasing);

                chartview->setParent(ui->horizontalFrame);

///******************************************************************************
    //map

         //   QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                             //  QCoreApplication::organizationName(), QCoreApplication::applicationName());

             ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/%D9%85%D8%B7%D8%A7%D8%B1+%D8%AA%D9%88%D9%86%D8%B3+%D9%82%D8%B1%D8%B7%D8%A7%D8%AC+%D8%A7%D9%84%D8%AF%D9%88%D9%84%D9%8A%E2%80%AD/@36.8475562,10.2197488,17z/data=!3m1!4b1!4m5!3m4!1s0x12e2cad2e1d7f1bb:0x902488d100b5819b!8m2!3d36.8475562!4d10.2175601");



///time*******************************************************************************************
             QTimer *timer = new QTimer(this);
              connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
              timer->start();
              QTimer *timer1 = new QTimer(this);
               connect(timer1, SIGNAL(timeout()), this, SLOT(mydate()));
               timer1->start();

               ///*******************ARDUINO******************************************
               /// *******************************************************************
               int ret=A.connect_arduino();
                           switch (ret)
                           {
                           case(0): qDebug() << "arduino  is available and connected to :" <<A.getarduino_port_name();
                               ui->label_24->setText("Arduino  is available and connected");
                               ui->label_24->setStyleSheet("QLabel {color : green; }");
                               arduino_connected=1;
                           break ;
                           case(1): qDebug() << "arduino  is available and not connected to :" <<A.getarduino_port_name();
                               if (arduino_connected==0)
                              { ui->label_24->setText("Arduino  is available and not connected");
                               ui->label_24->setStyleSheet("QLabel {color : yellow; }");}
                           break ;
                           case(-1): qDebug() << "arduino  is not available";
                               ui->label_24->setText("Arduino  is not available");
                               ui->label_24->setStyleSheet("QLabel {color : red; }");
                               arduino_connected=0;
                               break ;
                               }

                QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_labell()));
}

gestion_voyageur::~gestion_voyageur()
{
    delete ui;
}

//video
void gestion_voyageur::on_actionon_triggered()
{
    player= new QMediaPlayer;
    vw=new QVideoWidget;

  auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");


    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    vw->setGeometry(100,100,300,400);
     vw->show();
    player->play();
   // QDebug  <<player->state();

}

void gestion_voyageur::on_actionoff_triggered()
{
    player->stop();
    vw->close();
}


void gestion_voyageur::on_ajouter_clicked()
{
    // voyageur v;
     int cin=ui->lineEdit_cin->text().toInt();
     QString nom=ui->lineEdit_nom->text();
     QString prenom=ui->lineEdit_prenom->text();
     QString adresse=ui->lineEdit_adresse->text();
   QDate date_naissance=ui->dateEdit->date();
   QString code="";

     voyageur v(cin,nom,prenom,adresse,date_naissance,code);

        bool test=v.ajouter();
         //bool test1=v.recherchercin(v.getcin());
        if(test )
        {
            //mise a jour
            ui->table_voyageur->setModel(Etmp.afficher());
            stat();
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout  effectué \n ""click cancel to exist."),QMessageBox::Cancel);


            ui->lineEdit_cin->clear();
            ui->lineEdit_nom->clear();
             ui->lineEdit_prenom->clear();
             ui->lineEdit_adresse->clear();
              ui->dateEdit->clear();




        }
        else
            QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("ajout non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);


}



/*  v.setcin(ui->lineEdit_cin->text().toUInt());
    v.setnom(ui->lineEdit_nom->text());
    v.setprenom(ui->lineEdit_prenom->text());
    v.setadresse(ui->lineEdit_adresse->text());
    v.setdate(ui->dateEdit->date());

    //QString nom=v.getnom();
//    QMessageBox::warning(this,"vous avez enregistrer ","  nom:"+ nom +"  prenom:"
                 //        +v.getprenom()+"  adresse:"+v.getadresse()+"  date:"+v.getdate().toString("yyyy/dd/MM"));

      */
void gestion_voyageur::on_pushButton_supprimer_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    bool test=Etmp.supprimer(cin);
    if(test)
    {    //mise ajour
        ui->table_voyageur->setModel(Etmp.afficher());
         stat();
         QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué \n ""click cancel to exist."),QMessageBox::Cancel);

    }
    else  QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("suppression non effectué \n ""click cancel to exist."),QMessageBox::Cancel);
}







void gestion_voyageur::on_pushButton_modifier_clicked()
{ //int cin =ui->lineEdit_soc_2->text().toInt();

   int cin=ui->lineEdit_cin->text().toInt();
   QString nom=ui->lineEdit_nom->text();
   QString prenom=ui->lineEdit_prenom->text();
   QString adresse=ui->lineEdit_adresse->text();
      QDate date_naissance=ui->dateEdit->date();
 //voyageur v;
 //v.chercher(cin);



  bool test=Etmp.modifier(cin,adresse,nom,prenom,date_naissance);
  if(test)
  {  //mise a jour
      ui->table_voyageur->setModel(Etmp.afficher());
      stat();
      QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification  effectué \n ""click cancel to exist."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("modification non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);






}


void gestion_voyageur::on_pushButton_trie_clicked()
{
   voyageur v;
                QString choix=ui->comboBox_tri->currentText();
                if (choix=="nom")
                {
                    ui->table_voyageur->setModel(v.trie_NOM());
                    ui->table_voyageur->setModel(v.afficher());
                    bool test=v.trie_NOM();
                    if (test)
                    {

                ui->table_voyageur->setModel(v.trie_NOM());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri Nom effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri Nom failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
                if (choix=="cin")
                {
                    ui->table_voyageur->setModel(v.trie_CIN());
                    ui->table_voyageur->setModel(v.afficher());
                    bool test=v.trie_CIN();
                    if (test)
                    {

                ui->table_voyageur->setModel(v.trie_CIN());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri cin effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri cin failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
                if (choix=="adresse")
                {
                    ui->table_voyageur->setModel(v.trie_ADRESSE());
                    ui->table_voyageur->setModel(v.afficher());
                    bool test=v.trie_ADRESSE();
                    if (test)
                    {

                ui->table_voyageur->setModel(v.trie_ADRESSE());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri adresse effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri adresse failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }

}

void gestion_voyageur::on_pushButton_chercher_clicked()
{
     voyageur v;



     QString choix=ui->chercher->currentText();
     if (choix=="nom")
     {
         QString Nom = ui->lineEdit->text();
           ui->table_voyageur->setModel(v.recherchernom(Nom));

     }
     if (choix=="adresse")
     {
         QString adresse= ui->lineEdit->text();
                    ui->table_voyageur->setModel(v.rechercheradresse(adresse));

     }
     if (choix=="cin")
     {
        int cin = ui->lineEdit->text().toInt();
        QString cin_string=QString::number(cin);
         ui->table_voyageur->setModel(v.recherchercin(cin_string));

     }
    /*
    QString Nom = ui->lineEdit->text();
               ui->table_voyageur->setModel(m.recherchernom(Nom));*/
}
///click sur table view
void gestion_voyageur::on_table_voyageur_activated(const QModelIndex &index)
{
    QString val=ui->table_voyageur->model()->index(index.row(),index.column()).data().toString();

 /*Connection conn;
   if(!conn.createconnect())
 {
 qDebug()<<"failed to open the database";
     return;
 }*/

    QSqlQuery query;
    query.prepare("select * from voyageurs where cin='"+val+"' " );   // or  nom='"+val+"'   or prenom='"+val+"'    or adresse='"+val+"'

if(query.exec())
{   while(query.next())
    {
        ui->lineEdit_cin->setText(query.value(0).toString());
        ui->lineEdit_nom->setText(query.value(1).toString());
        ui->lineEdit_prenom->setText(query.value(2).toString());
        ui->lineEdit_adresse->setText(query.value(3).toString());

    }

//conn.closeConnection();
}
else
    QMessageBox::critical(this,tr("error::"),query.lastError().text());


}

///PDF*****************************************
int gestion_voyageur::on_pushButton_clicked()
{
  /*  QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("voyageurs.pdf");
          QPainter painter;
          QImage logo(":/new/prefix1/logo");
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              return 1;
          }
          painter.drawImage(-40,-40,logo);
          painter.drawText(40, 10, "Liste des voyageurs");
          painter.drawText(40, 30, "voy 1");
          painter.drawText(40, 50, "voy 2");
          if (! printer.newPage()) {
              qWarning("failed in flushing page to disk, disk full?");
              return 1;
          }

          painter.drawText(50, 100, "Finish Test");
          painter.end();
          */
    //***************************************
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->table_voyageur->model()->rowCount();
                const int columnCount =ui->table_voyageur->model()->columnCount();
                 //  QPainter painter;
                     QImage logo(":/new/prefix1/logo");

                     out<<     "<h2>logo:</h2>"
                          "<img src=':/new/prefix1/logo' height='90' width='80'/>";


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#e8ceeb link=#5000A0>\n" ///#bfa1c2 reference du couleur violet

                            "<h1>Liste des voyageurs</h1>"

                  "<table border=1 cellspacing=10 cellpadding=10>\n";



                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->table_voyageur->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->table_voyageur->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->table_voyageur->isColumnHidden(column)) {
                                   QString data = ui->table_voyageur->model()->data(ui->table_voyageur->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                               }
                           }
                           out << "</tr>\n";

                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";


        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("gestion_voyageurs.pdf");
        document->print(&printer);

        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                          if (reponse == QMessageBox::Yes)
                          {
                              QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/eya sheikhrouhou/Desktop/bagage/build-gestion_bagage-Desktop_Qt_5_9_9_MinGW_32bit-Debug/gestion_voyageurs.pdf"));

                             // painter.end();
                          }
                          if (reponse == QMessageBox::No)
                          {
                              //painter.end();
                          }
                         // painter.end();




}





void gestion_voyageur::on_pushButton_3_clicked()
{/*
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                     tr("Excel Files (*.xls)"));
     if (fileName.isEmpty())
         return;
       //instance                              //sheet title
     ExportExcelObject obj(fileName, "mydata", ui->table_voyageur); //ken ektebech my data failed by DRIVER={Microsoft Excel Driver (*.xls)}.

     //colums to export
     obj.addField(0, "CIN", "char(20)");
     obj.addField(1, "NOM", "char(20)");
     obj.addField(2, "PRENOM", "char(20)");
     obj.addField(3, "ADRESSE", "char(20)");
     obj.addField(4, "DATE8NAISSANCE", "char(20)");



     int retVal = obj.export2Excel();
     if( retVal > 0)
     {
         QMessageBox::information(this, tr("Done"),
                                  QString(tr("%1 records exported!")).arg(retVal)
                                  );
      }
*/



    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                     tr("Excel Files (*.xls)"));
     if (fileName.isEmpty())
         return;

     ExportExcelObject obj(fileName, "liste voyageurs", ui->table_voyageur);

     //colums to export
     obj.addField(0, "CIN", "char(20)");
     obj.addField(1, "NOM", "char(20)");
     obj.addField(2, "PRENOM", "char(20)");
     obj.addField(3, "ADRESSE", "char(20)");
     obj.addField(4, "DATE8NAISSANCE", "char(20)");
        obj.addField(5, "code", "char(20)");




     int retVal = obj.export2Excel();
     if( retVal > 0)
     {
         QMessageBox::information(this, tr("Done"),
                                  QString(tr("%1 records exported!")).arg(retVal)
                                  );
      }
}


void gestion_voyageur::on_imprimer_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->table_voyageur->model()->rowCount();
            const int columnCount = ui->table_voyageur->model()->columnCount();
            QString TT = QDateTime::currentDateTime().toString();
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - VOYAGEURS LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  voyageurs ******"+TT+" </strong></h1>"
                   +"<img src=':/new/prefix1/logo' height='90' width='80'/>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->table_voyageur->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->table_voyageur->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->table_voyageur->isColumnHidden(column)) {
                        QString data =ui->table_voyageur->model()->data(ui->table_voyageur->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void gestion_voyageur::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, tr("choose"), "", tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
        if(QString::compare(filename,QString())!=0)
        {
            QImage image;
            bool valid = image.load(filename);
            if(valid)
            {
                ui->placeimage->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                      QObject::tr("Image non effectuée.\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
            }
        }
}


void gestion_voyageur::myfunction()
{
  // qDebug() << "update..";

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if ((time.second() % 2)==  0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ' ;
    }
    ui->label_time->setText(time_text);

}
void gestion_voyageur::mydate()
{
  // qDebug() << "update..";

    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");

    ui->label_date->setText(date_text);

}
void gestion_voyageur::stat()
{
    int cin=0;
          QString nom="";
          QString prenom="";
          QString adresse="";
          QDate date_naissance;
  QString code="";

        voyageur m(cin,nom,prenom,adresse,date_naissance,code);






                  QPieSeries *series = new QPieSeries();
                  series->setHoleSize(0.35);


                  int nbr=m.statistique("Tunis");
                  int nbrr=m.statistique("Sfax");
                  int nbrrr=m.statistique("Sousse");
                  int nb=m.statistique("Siliana");
                  int total=nbr+nbrr+nbrrr+nb;

                  QString a=QString("Tunis "+QString::number((nbr*100)/total,'f',2)+"%" );
                  QString b=QString("Sfax "+QString::number((nbrr*100)/total,'f',2)+"%" );
                  QString c=QString("Sousse "+QString::number((nbrrr*100)/total,'f',2)+"%" );
                  QString d=QString("Siliana "+QString::number((nb*100)/total,'f',2)+"%" );
                  QPieSlice *slice = series->append(d,nb);
                  slice->setExploded();
                  slice->setLabelVisible();
                  series->append(a,nbr);
                  series->append(b, nbrr);
                  series->append(c, nbrrr);

                  QChart *chart = new QChart();
                  chart->addSeries(series);
                  chart->setAnimationOptions(QChart::SeriesAnimations);
                  chart->setTitle("statistiques parlieu");
                  chart->setTheme(QChart::ChartThemeBlueIcy);


                  QChartView *chartview = new QChartView(chart);
                  chartview->setRenderHint(QPainter::Antialiasing);

                  chartview->setParent(ui->horizontalFrame);



}


void gestion_voyageur::update_labell()
{
    data=A.read_from_arduino();



    QString Message;
        qDebug()<<"oui";
        for (int i=0;i<data.length();i++)
        {
            code=code+data[i];
        }
        if (code.contains("\r\n"))   //\r stands for “Carriage Return”
        {
            Message="Carte RFID introuvable dans la base de données";
            code.remove("\r\n");
            ui->rfid_code_line->setText(code);



                   // QSqlQuery qry;
                  // qry.prepare( " select * from voyageurs where cin =:data");
                  // qry.bindValue(":code",data);
                   int cin =ui->lineEdit_2->text().toInt();
                     int cin_supp =ui->lineEdit_3->text().toInt();
                   QSqlQuery query;

                  QString cin_string=QString::number(cin);
                  QString cinsupp_string=QString::number(cin_supp);


                   bool test=Etmp.modifier_code(code,cin_string);

                   if(test)
                   {  //mise a jour
                       ui->table_voyageur->setModel(Etmp.afficher());

                      // QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("RFID effectué \n ""click cancel to exist."),QMessageBox::Cancel);
                   }
                   else
                       QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("RFID non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);





                      Etmp.supprimer(cin_supp);
                       ui->table_voyageur->setModel(Etmp.afficher());





                 }


}
