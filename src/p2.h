#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H

#include <vector>


template <typename Container>
using que_tipo = typename Container::value_type;


template <typename Container>
Container sum_range(const Container& c1, const Container& c2) {
    Container resultado;

    auto i1 = std::begin(c1);
    auto end1 = std::end(c1);
    auto i2 = std::begin(c2);
    auto end2 = std::end(c2);
    auto tam1 = std::distance(std::begin(c1), std::end(c1));
    auto tam2 = std::distance(std::begin(c2), std::end(c2));

    bool c1_es_mayor = (tam1 >= tam2);


    auto it_mayor = c1_es_mayor ? i1 : i2;
    auto end_mayor = c1_es_mayor ? end1 : end2;
    auto it_menor = c1_es_mayor ? i2 : i1;
    auto end_menor = c1_es_mayor ? end2 : end1;

    if constexpr (requires(Container c, size_t s) { c.reserve(s); }) {
        resultado.reserve(std::distance(it_mayor, end_mayor));
    }

    while (it_mayor != end_mayor) {
        if (it_menor == end_menor) it_menor = std::begin(c2);

        resultado.insert(resultado.end(),(*it_mayor) + (*it_menor));

        ++it_mayor;
        ++it_menor;
    }

    return resultado;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
