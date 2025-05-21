#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H

#include <unordered_set>

template <typename Container>
Container delete_duplicated(const Container& x) {
    Container rpta;
    std::unordered_set<typename Container::value_type> seen;

    for (const auto& item : x) {
        if (seen.insert(item).second) {
            rpta.push_back(item);
        }
    }

    return rpta;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
