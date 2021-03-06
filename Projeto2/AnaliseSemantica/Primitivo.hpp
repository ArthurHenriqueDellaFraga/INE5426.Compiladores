#pragma once

#include "Contexto.hpp"

using namespace std;

namespace AnaliseSemantica {

  // ABSTRAÇÃO

  template <typename T>
  class PrimitivoAbstrato : public Nodo<T> {
      protected:
          T valor;

          PrimitivoAbstrato(){ }
          PrimitivoAbstrato(T valor) : valor(valor){ }

          void print(){
              cout << "valor ";
              this->getTipo()->print();
              cout << " " << valor;
          }

          T executar(Contexto* contexto){
              return valor;
          }
  };

  template <>
  class PrimitivoAbstrato<void> : public Nodo<void> {
      protected:
          PrimitivoAbstrato(){ }

          void print(){
              cout << "valor ";
              this->getTipo()->print();
          }
  };

  // INSTANCIAÇÃO

  template<typename T>
  class Primitivo : public PrimitivoAbstrato<T>{
      public:
          Primitivo() : PrimitivoAbstrato<T>(){ }
          Primitivo(T valor) : PrimitivoAbstrato<T>(valor){ }
  };

  template<>
  class Primitivo<void> : public PrimitivoAbstrato<void>{
      public:
          Primitivo() : PrimitivoAbstrato<void>(){ }
  };

  template<>
  class Primitivo<bool> : public PrimitivoAbstrato<bool>{
      public:
          Primitivo(bool valor) : PrimitivoAbstrato<bool>(valor){ };

          void print(){
              cout << "valor ";
              this->getTipo()->print();
              if(valor){
                  cout << " TRUE";
              }else{
                  cout << " FALSE";
              }
          }
  };

  // POLIMORFISMO

  class PrimitivoPolimorfo : public NodoPolimorfo<Primitivo>{
      public:
          template <typename U>
          PrimitivoPolimorfo(Primitivo<U>* primitivo) : NodoPolimorfo<Primitivo>(primitivo){ }
  };

  typedef PrimitivoPolimorfo PrimitivoFundamental;

}
