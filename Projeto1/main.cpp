#include "AnaliseSemantica/Contexto.hpp"

#include <iostream>

using namespace AnaliseSemantica;

Bloco* raizDoPrograma; //set on Bison file
Contexto* contexto;
bool debug = true;

extern int yyparse();

int main(int argc, char **argv){

    contexto = new Contexto();

    yyparse();                  //parses whole data
    raizDoPrograma->print();
    raizDoPrograma->executar(contexto);

    return 0;
}
