#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H

#include <vector>
#include <list>
#include <iterator>

template <typename Container, typename... Containers>
auto zip(const Container& first, const Containers&... rest) {
    using ValueType = typename Container::value_type;
    using ResultType = std::list<std::vector<ValueType>>;


    auto check_size = [](const auto& c1, const auto& c2) {
        return std::distance(std::begin(c1), std::end(c1)) == std::distance(std::begin(c2), std::end(c2));
    };

    if (!(check_size(first, rest) && ...)) {
        throw std::invalid_argument("ERROR: Containers do not have same size");
    }
    ResultType result;
    auto i = std::make_tuple(std::begin(first), std::begin(rest)...);
    auto ends = std::make_tuple(std::end(first), std::end(rest)...);

    while (std::get<0>(i) != std::get<0>(ends)) {
        std::vector<ValueType> row;
        std::apply([&](auto&... its) { ((row.push_back(*its++)), ...); }, i);
        result.push_back(std::move(row));
    }

    return result;
}
#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
