#pragma once

#include "AnaliseSemantica.hpp"

#include <iostream>

using namespace boost;
using namespace std;

namespace AnaliseSemantica {

  template <typename T>
  class Tipo;

  typedef Polimorfo<
      Tipo<int>*, Tipo<double>*,
      Tipo<bool>*,
      Tipo<char>*, Tipo<string>*
  > TipoFundamental;

  template <typename T = void>
  class Tipo{
      public:
          static TipoFundamental instanciar(string identificador){
              map<string, TipoFundamental(*)()> _tipo;
                _tipo["int"] = &createTipo<int>;
                _tipo["double"] = &createTipo<double>;
                _tipo["bool"] = &createTipo<bool>;
                _tipo["char"] = &createTipo<char>;
                _tipo["string"] = &createTipo<string>;

                return _tipo[identificador]();
          }

      protected:
          template <typename U>
          static TipoFundamental createTipo(){
              TipoFundamental tipo;
              tipo = new Tipo<U>();
              return tipo;
          }
  };

  template<>
  class Tipo<int> {
      private:
          string identificadorMasculino = "inteiro";
          string identificadorFeminino = "inteira";


      public:
          string getIdentificadorMasculino(){
              return identificadorMasculino;
          }

          string getIdentificadorFeminino(){
              return identificadorFeminino;
          };
  };

  template<>
  class Tipo<double> {
      private:
          string identificador = "real";

      public:
          string getIdentificadorMasculino(){
              return identificador;
          }

          string getIdentificadorFeminino(){
              return identificador;
          };
  };

  template<>
  class Tipo<bool> {
      private:
          string identificadorMasculino = "booleano";
          string identificadorFeminino = "booleana";


      public:
          string getIdentificadorMasculino(){
              return identificadorMasculino;
          }

          string getIdentificadorFeminino(){
              return identificadorFeminino;
          };
  };

  template<>
  class Tipo<char> {
      private:
          string identificador = "char";

      public:
          string getIdentificadorMasculino(){
              return identificador;
          }

          string getIdentificadorFeminino(){
              return identificador;
          };
  };

  template<>
  class Tipo<string> {
      private:
          string identificador = "string";

      public:
          string getIdentificadorMasculino(){
              return identificador;
          }

          string getIdentificadorFeminino(){
              return identificador;
          };
  };

}
