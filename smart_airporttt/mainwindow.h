#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<voyageur.h>

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


    void on_pushButton_supprimer_clicked();


    void on_pushButton_modifier_clicked();

    void on_ajouter_clicked();

    void on_pushButton_trie_clicked();

    void on_pushButton_chercher_clicked();

    void on_table_voyageur_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    voyageur Etmp;   //why j ai ajouter hedha lahneeeee

};
#endif // MAINWINDOW_H
