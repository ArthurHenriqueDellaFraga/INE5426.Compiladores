#pragma once

#include "Contexto.hpp"

using namespace boost;
using namespace std;

namespace AnaliseSemantica {

  //template <typename T = void>
  class Bloco : public Nodo<void> {
      protected:
          vector<NodoFundamental*> listaDeInstrucoes;
      public:
          Bloco(){}

          virtual void print(){
              for(int i=0; i < listaDeInstrucoes.size(); i++){
                  listaDeInstrucoes[i]->print();
                  cout << endl;
              }
          }

          void executar(Contexto* contexto){
              Contexto* novoContexto = new Contexto(contexto);
  
              for(int i=0; i < listaDeInstrucoes.size(); i++){
                  listaDeInstrucoes[i]->executar(novoContexto);
              }
          }

          void addInstrucao(NodoFundamental* instrucao){
              listaDeInstrucoes.push_back(instrucao);
          }
  };

}
