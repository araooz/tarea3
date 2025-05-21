#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H

template<typename... Args>
std::tuple<Args&...> unpack(Args&... args) {
    return std::tie(args...);
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
