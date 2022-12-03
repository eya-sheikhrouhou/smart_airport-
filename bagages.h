#ifndef BAGAGES_H
#define BAGAGES_H
#include <QMainWindow>
//#include"includers.h"
#include"arduino.h"
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
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
    void on_returnm_clicked();

private:
    Ui::MainWindow *ui;

    QByteArray data; // variable contenant les données reçues

  //  Arduino A; // objet temporaire

};
#endif // BAGAGES_H
