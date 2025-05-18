//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p7.h"
#include <vector>
#include <list>
#include <iterator>
using namespace std;

static void test_1() {
    vector<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res =rotate_range(cnt, 2);
    for (const auto& item : res)
        cout << item << " ";
}

static void test_2() {
    vector<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res =rotate_range(cnt, -3);
    for (const auto& item : res)
        cout << item << " ";
}

static void test_3() {
    list<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res =rotate_range(cnt, 2);
    for (const auto& item : res)
        cout << item << " ";
}

static void test_4() {
    list<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res =rotate_range(cnt, -2);
    for (const auto& item : res)
        cout << item << " ";
}

TEST_CASE("Question #7_1") {
    execute_test("test_7_1.in", test_1);
}

TEST_CASE("Question #7_2") {
    execute_test("test_7_2.in", test_2);
}

TEST_CASE("Question #7_3") {
    execute_test("test_7_3.in", test_3);
}

TEST_CASE("Question #7_4") {
    execute_test("test_7_4.in", test_4);
}