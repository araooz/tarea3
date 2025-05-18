//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p4.h"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

static void test_1() {
    vector<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res1 = delete_duplicated(cnt);
    for (const auto& item : res1)
        cout << item << " ";
}

static void test_2() {
    list<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res1 = delete_duplicated(cnt);
    for (const auto& item : res1)
        cout << item << " ";
}

TEST_CASE("Question #4_1") {
    execute_test("test_4_1.in", test_1);
}
TEST_CASE("Question #4_2") {
    execute_test("test_4_1.in", test_2);
}