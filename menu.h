#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"bagages.h"
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
   void hide_button() ;

private slots:
   void on_bagages_clicked();

private:
    Ui::menu *ui;
    MainWindow bagage ;
};

#endif // MENU_H
