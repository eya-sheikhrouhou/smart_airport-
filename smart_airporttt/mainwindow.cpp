#include "mainwindow.h"
#include "ui_mainwindow.h"
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
// ******************



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_voyageur->setModel(Etmp.afficher()); //affichage

    QPixmap pix("C:/Users/eya sheikhrouhou/Documents/smart_airport/Screenshot 2022-09-20 202443.png");
  ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
  ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));


  //statistiques***********************************

  int cin=0;
        QString nom="";
        QString prenom="";
        QString adresse="";
        QDate date_naissance;


      voyageur m(cin,nom,prenom,adresse,date_naissance);



            QPieSeries *series = new QPieSeries();
            series->setHoleSize(0.35);

            QPieSlice *slice = series->append("Siliana", m.statistique("Siliana"));

            slice->setExploded();
            slice->setLabelVisible();
            series->append("Sfax", m.statistique("Sfax"));
            series->append("Tunis", m.statistique("Tunis"));
            series->append("Sousse", m.statistique("Sousse"));

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTitle("statistiques par Adresse");
            chart->setTheme(QChart::ChartThemeBlueIcy);


            QChartView *chartview = new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);

            chartview->setParent(ui->horizontalFrame);

    //map

            QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                               QCoreApplication::organizationName(), QCoreApplication::applicationName());

             ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");



}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_ajouter_clicked()
{
    // voyageur v;
     int cin=ui->lineEdit_cin->text().toInt();
     QString nom=ui->lineEdit_nom->text();
     QString prenom=ui->lineEdit_prenom->text();
     QString adresse=ui->lineEdit_adresse->text();
    QDate date_naissance=ui->dateEdit->date();


     voyageur v(cin,nom,prenom,adresse,date_naissance);

        bool test=v.ajouter();
         bool test1=v.recherchercin(v.getcin());
        if(test )
        { if(test1){
            //mise a jour
            ui->table_voyageur->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout  effectué \n ""click cancel to exist."),QMessageBox::Cancel);


            ui->lineEdit_cin->clear();
            ui->lineEdit_nom->clear();
             ui->lineEdit_prenom->clear();
             ui->lineEdit_adresse->clear();
              ui->dateEdit->clear();



            }
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
void MainWindow::on_pushButton_supprimer_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    bool test=Etmp.supprimer(cin);
    if(test)
    {    //mise ajour
        ui->table_voyageur->setModel(Etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué \n ""click cancel to exist."),QMessageBox::Cancel);

    }
    else  QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("suppression non effectué \n ""click cancel to exist."),QMessageBox::Cancel);
}







void MainWindow::on_pushButton_modifier_clicked()
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
      QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification  effectué \n ""click cancel to exist."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("modification non   effectué \n ""click cancel to exist."),QMessageBox::Cancel);






}


void MainWindow::on_pushButton_trie_clicked()
{
   voyageur m;
                QString choix=ui->comboBox_tri->currentText();
                if (choix=="nom")
                {
                    ui->table_voyageur->setModel(m.trie_NOM());
                    ui->table_voyageur->setModel(m.afficher());
                    bool test=m.trie_NOM();
                    if (test)
                    {

                ui->table_voyageur->setModel(m.trie_NOM());
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
                    ui->table_voyageur->setModel(m.trie_CIN());
                    ui->table_voyageur->setModel(m.afficher());
                    bool test=m.trie_CIN();
                    if (test)
                    {

                ui->table_voyageur->setModel(m.trie_CIN());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri prix effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri prix failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }

}

void MainWindow::on_pushButton_chercher_clicked()
{
     voyageur m;
     /*
     QString nom=ui->lineEdit->text();

     ui->table_voyageur->setModel(m.chercher(nom));

     bool test=m.chercher(nom);
     if (test)
     {

 ui->table_voyageur->setModel(m.chercher(nom));
         QMessageBox::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("recherche effectué \n"
                                              "Click Cancel to exist ."),QMessageBox::Cancel);

     }
     else
           QMessageBox::critical(nullptr, QObject::tr("non"),
                       QObject::tr("recherche  failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);*
         */
    QString Nom = ui->lineEdit->text();
               ui->table_voyageur->setModel(m.recherchernom(Nom));
}

void MainWindow::on_table_voyageur_activated(const QModelIndex &index)
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

















int MainWindow::on_pushButton_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("voyageurs.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              return 1;
          }
          painter.drawText(40, 10, "Liste des voyageurs");
          painter.drawText(40, 30, "voy 1");
          painter.drawText(40, 50, "voy 2");
          if (! printer.newPage()) {
              qWarning("failed in flushing page to disk, disk full?");
              return 1;
          }
          painter.drawText(10, 40, "Finish Test");
          painter.end();
}
