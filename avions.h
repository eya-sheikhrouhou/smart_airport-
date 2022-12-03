#ifndef AVIONS_H
#define AVIONS_H

#include <Avion.h>
#include "smtp.h"
#include "arduino.h"
#include <QMainWindow>

#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include <QAbstractTableModel>
#include <QTableView>

#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui {

   class avions;

             } //namespace end
QT_END_NAMESPACE



class avions : public QDialog
{
    Q_OBJECT

public:
    avions(QDialog *parent = nullptr);

    ~avions();



private slots:

    void on_pb_ajouter_clicked();
    void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_chercher_clicked();
    void on_pb_trier_clicked();
    int on_pb_pdf_clicked();

    //void sendMail();
    void mailSent(QString);
    void browse();
    void on_sendBtn_clicked();

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino


    void on_verif_clicked();

    void on_tester_clicked();

private:
    Ui::avions *ui;
    Avion A;
    QStringList files;

    QByteArray data; // variable contenant les données reçues
    Arduino Ar; // objet temporaire

    using QDialog::QDialog;


};



#endif // AVIONS_H
