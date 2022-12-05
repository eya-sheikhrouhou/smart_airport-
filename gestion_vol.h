#ifndef GESTION_VOL_H
#define GESTION_VOL_H

#include <QWidget>
#include "vol.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


namespace Ui {
class gestion_vol;
}

class gestion_vol : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_vol(QWidget *parent = nullptr);
    ~gestion_vol();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_pdf_clicked();
    void on_pb_supprimer_clicked();
   // void on_pb_chercher_clicked();

    void on_pb_chercher_clicked();

    void on_pb_trier_clicked();

private:
    Ui::gestion_vol *ui;
    Vol V;

};

#endif // GESTION_VOL_H
