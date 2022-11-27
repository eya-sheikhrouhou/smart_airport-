#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QMainWindow>
#include "employes.h"
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
/*public slots:
 int employePDF();*/

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_3_clicked();//supprimer

    void on_pushButton_modifier_clicked();

    void on_pushButton_carte_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_clicked();

    void on_pushButton_search_tri_clicked();


private:
    Ui::MainWindow *ui;
    Employes Emp;

public slots:

};
#endif // MAINWINDOW_H
