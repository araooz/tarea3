#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H

#include <fstream>
#include <vector>
#include <forward_list>
#include <algorithm>

template <template <typename, typename> class Container = std::vector>
auto filter_codes(const std::string& name, char inicial){

    using Cont = Container<std::string, std::allocator<std::string>>;
    Cont resultado;

    std::ifstream file(name);
    if (!file.is_open()){
        return resultado;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        if (!linea.empty() && linea[0] == inicial) {
            if constexpr (std::is_same<Cont, std::forward_list<std::string>>::value) {
                resultado.push_front(linea);
            } else {
                resultado.push_back(linea);
            }
        }
    }
    file.close();

    if constexpr (std::is_same<Cont, std::forward_list<std::string>>::value) {
        resultado.sort();
        resultado.reverse(); // porque usamos push_front, invertimos para orden ascendente
    } else {
        std::sort(resultado.begin(), resultado.end());
    }

    return resultado;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
