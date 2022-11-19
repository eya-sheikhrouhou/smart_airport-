#ifndef BAGAE_H
#define BAGAE_H
#include<QString>


class bagage
{
public:

   bagage();
   bagage(QString) ;

   void set_CIN(QString) ;
   void set_poids_sup(float);

   QString get_numbg();
   float get_fraisB();
   float get_poidsSup();
   float get_poids() ;

private:
    QString num_bg ;
    QString CIN ;
    float frais_B , poids ,poids_sup;
};

#endif // BAGAE_H
