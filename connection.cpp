#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setPort(1521);
db.setDatabaseName("source_projet2A");
db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("Eya27301241");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
