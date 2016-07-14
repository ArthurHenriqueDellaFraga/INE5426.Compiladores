#pragma once

#include "../Operacao.hpp"

using namespace std;

namespace AnaliseSemantica {

  // INSTANCIAÇÃO

  template <typename T>
  class Diferente : public Operacao<bool, T, T>{
      public:
          Diferente(Nodo<T>* left, Nodo<T>* right) : Operacao<bool, T, T>(left, "diferente", right){ }

          bool executar(Contexto* contexto){
              return (this->left->executar(contexto)) != (this->right->executar(contexto));
          }

          static NodoFundamental* instanciar(NodoFundamental* left, NodoFundamental* right){
              return apply_visitor(create_visitor (), *left, *right);
          }

      protected:
        struct create_visitor : public static_visitor<NodoFundamental*>{
            template <typename V, typename W>
            NodoFundamental* operator()(Nodo<V>*& left, Nodo<W>*& right) const {
                  NodoFundamental* l = new NodoFundamental(left);
                  NodoFundamental* r = new NodoFundamental(right);

                  NodoFundamental* conversao = Conversao<>::instanciar(l->getTipo(), r);
                  return Diferente::instanciar(l, conversao);
            }

            template <typename V>
            NodoFundamental* operator()(Nodo<V>*& left, Nodo<V>*& right) const {
                return new NodoFundamental(new Diferente<V>(left, right));
            }


            // Verificar necessidade:
            NodoFundamental* operator()(Nodo<void>*& left, Nodo<void>*& right) const {
              throw new Erro("Comparação inválida");
            }
        };
  };

}
