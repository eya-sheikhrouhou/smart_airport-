#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPixmap>
#include<QMessageBox>
#include<QString>
#include <QMainWindow>
#include<QWidget>
#include<iostream>
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_supp_info_clicked();
    void on_id_search_button_clicked();
    void on_add_info_clicked();
    void on_confirm_ajout_clicked();
    void on_modify_poids_clicked();
    void on_add_poids_sup_clicked();
    void on_ajouter_clicked();
    void on_supp_clicked();
    void on_pdf_clicked();
    void on_tri_clicked();

    void on_affichetout_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
