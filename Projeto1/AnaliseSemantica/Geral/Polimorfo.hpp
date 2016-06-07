#pragma once

#include "boost/variant.hpp"
#include "boost/variant/apply_visitor.hpp"
#include "boost/variant/static_visitor.hpp"

#include <iostream>

using namespace boost;

namespace AnaliseSemantica {

    template <template <typename> class T>
    class Polimorfo : public variant<T<int>*, T<double>*, T<bool>*, T<char>*, T<string>*, T<void>*>{
        public:
            typedef variant<T<int>*, T<double>*, T<bool>*, T<char>*, T<string>*, T<void>*> Super;

            template<typename U>
            Polimorfo(const T<U>*& t){
                *this = t;
            };

            // Polimorfo() : variant<Types...>(){}

            template<typename U>
            Polimorfo<T>& operator=(const T<U>*& t){
                Super::operator=(t);
                return *this;
            }
      };

}
