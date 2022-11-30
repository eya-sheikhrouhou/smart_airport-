#include "bagages.h"
#include <QApplication>
#include "connection.h"
#include<QDebug>
#include <QMessageBox>
#include "login.h"
#include"menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      Connection c;
    login w;



    //gestion_voyageur v;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();

}
