#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqldatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnexion();
};

#endif // CONNECTION_H
