#pragma once

#include "Variavel.hpp"
#include "Arranjo.hpp"

using namespace std;

namespace AnaliseSemantica {

    class Contexto {
        public:
            map<string, VariavelFundamental*> _variavel;
            map<string, ArranjoFundamental*> _arranjo;

            Contexto(){ }

            Contexto(Contexto* contexto){
                this->_variavel = contexto->_variavel;
                this->_arranjo = contexto-> _arranjo;
            }

            void put(string identificador, VariavelFundamental* variavel){
                map<string, VariavelFundamental*>::iterator it;
                it = _variavel.find(identificador);

                if(it != _variavel.end()){
                    throw new Erro("variavel " + identificador + " sofrendo redefinicao");
                }

                _variavel[identificador] = variavel;
            }

            VariavelFundamental* getVariavel(string identificador){
                map<string, VariavelFundamental*>::iterator it;
                it = _variavel.find(identificador);

                if(it == _variavel.end()){
                    Erro* erro = new Erro("variavel " + identificador + " sem declaracao");
                    erro->print();

                    return new VariavelFundamental(new Variavel<void>(identificador));
                }

                return _variavel[identificador];
            }

            void putArranjo(string identificador, ArranjoFundamental* arranjo){
                map<string, ArranjoFundamental*>::iterator it;
                it = _arranjo.find(identificador);

                if(it != _arranjo.end()){
                    throw new Erro("arranjo sofrendo redefinicao");
                }

                _arranjo[identificador] = arranjo;
            }

            ArranjoFundamental* getArranjo(string identificador){
                map<string, ArranjoFundamental*>::iterator it;
                it = _arranjo.find(identificador);

                if(it == _arranjo.end()){
                  Erro* erro = new Erro("arranjo " + identificador + " sem declaracao");
                  erro->print();

                  return new ArranjoFundamental(new Arranjo<void>(identificador, 0));
                }

                return _arranjo[identificador];
            }

    };
}
