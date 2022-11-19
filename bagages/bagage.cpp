#include "bagage.h"

bagage::bagage()
{
   CIN="" ;
   num_bg="" ;
   frais_B=0 ;
   poids =0 ;
   poids_sup =0;
}

bagage::bagage(QString id) {
    CIN=id ;
    num_bg="" ;
    frais_B=0 ;
    poids =0 ;
    poids_sup =0;
}


QString bagage::get_numbg(){return num_bg ;}
float bagage::get_fraisB(){return frais_B; }
float bagage::get_poidsSup(){return poids_sup ;}
float bagage::get_poids() {return poids ; }


void bagage::set_CIN(QString id){
    CIN=id ;
}

void bagage::set_poids_sup(float ps){
    poids_sup=ps ;
}
