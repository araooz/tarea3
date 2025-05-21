#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H

#include <algorithm>

template<typename Container>
Container rotate_range(const Container& c, int x) {
    Container rpta(c);
    auto tamano = std::distance(std::begin(rpta), std::end(rpta));

    if (tamano == 0) {
        return rpta;
    }

    x = (x % tamano + tamano) % tamano;

    auto first = std::begin(rpta);
    auto rot_start = first;
    std::advance(rot_start, tamano - x);

    std::rotate(first, rot_start, std::end(rpta));

    return rpta;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
