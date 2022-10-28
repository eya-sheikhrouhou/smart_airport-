#include "bagage.h"

bagage::bagage()
{
   id="" ;
}

void bagage:: set_id(QString n ){id=n; }
QString bagage:: get_name( ){return name ;  }
QString bagage:: get_pname(){return pname ; }
QString bagage:: get_adr(){return adress ; }
QString bagage:: get_cin(){return cin ; }

