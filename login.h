#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "bagages.h"
#include "menu.h"

#include"includers.h"

#include"arduino.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
    int on_add_info_clicked();



private:
    Ui::login *ui;
    MainWindow main ;
    menu mn ;
    Arduino A ;

};

#endif // LOGIN_H
