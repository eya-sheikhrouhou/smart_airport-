#ifndef BAGAE_H
#define BAGAE_H
#include<QString>


class bagage
{
public:
    void set_id(QString n);
    QString get_name() ;
    QString get_pname() ;
    QString get_adr() ;
    QString get_cin() ;

    bagage();
private:
    QString name,pname, adress, cin , id;
};

#endif // BAGAE_H
