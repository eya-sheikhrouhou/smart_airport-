#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"mainwindow.h"

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

private:
    Ui::menu *ui;
    MainWindow bagages ;
};

#endif // MENU_H
