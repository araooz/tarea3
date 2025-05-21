#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H

#include <algorithm>
#include <set>

template <typename Container, typename T, typename = typename std::enable_if<!std::is_same<T, std::initializer_list<typename Container::value_type>>::value>::type>
Container delete_range(const Container& cont, const T& valor_a_eliminar) {
    Container resultado;

    auto inser = std::inserter(resultado, std::end(resultado));
    std::copy_if(std::begin(cont), std::end(cont), inser,[&valor_a_eliminar](const auto& x) { return x != valor_a_eliminar; });

    return resultado;
}
template <typename Container>
Container delete_range(const Container& cont, std::initializer_list<typename Container::value_type> valores_a_eliminar) {
    Container resultado;

    std::set<typename Container::value_type> deleteable(valores_a_eliminar.begin(), valores_a_eliminar.end());
    auto inser = std::inserter(resultado, std::end(resultado));
    std::copy_if(std::begin(cont), std::end(cont), inser,[&deleteable](const auto& x) {
                     return deleteable.find(x) == deleteable.end();
                 });
    return resultado;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
