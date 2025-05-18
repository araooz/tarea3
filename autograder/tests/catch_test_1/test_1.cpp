//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p1.h"
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>

using namespace std;

static void test_1() {
    deque<int> cnt {istream_iterator<int>(cin), istream_iterator<int>()};
    auto res1 = split_range(cnt, 4);
    for (const auto& row : res1) {
        for (const auto& item : row)
            cout << item << " ";
    }
}

static void test_2() {
    list<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res2 = split_range(cnt, 2);
    for (const auto& row : res2) {
        for (const auto& item : row)
            cout << item << " ";
    }
}

static void test_3() {
    vector<int> vec{istream_iterator<int>(cin), istream_iterator<int>()};
    forward_list<int> cnt{begin(vec), end(vec)};
    auto res3 = split_range(cnt, 3);
    for (const auto& row : res3) {
        for (const auto& item : row)
            cout << item << " ";
    }
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", test_1);
}
TEST_CASE("Question #1_2") {
    execute_test("test_1_1.in", test_2);
}
TEST_CASE("Question #1_3") {
    execute_test("test_1_1.in", test_3);
}