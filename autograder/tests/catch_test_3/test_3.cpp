//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p3.h"
#include <list>
#include <deque>
#include <iterator>
using namespace std;

static void test_1() {
    list<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res1 = delete_range(cnt, 2);
    for (const auto& item : res1)
        cout << item << " ";
}

static void test_2() {
    list<int> cnt {istream_iterator<int>(cin), istream_iterator<int>()};
    auto res2 = delete_range(cnt, { 1, 2 });
    for (const auto& item : res2)
        cout << item << " ";
}

static void test_3() {
    deque<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res3 = delete_range(cnt, 2);
    for (const auto& item : res3)
        cout << item << " ";

}

static void test_4() {
    deque<int> cnt{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res4 = delete_range(cnt, { 1, 2 });
    for (const auto& item : res4)
        cout << item << " ";
}

TEST_CASE("Question #3_1") {
    execute_test("test_3_1.in", test_1);
}

TEST_CASE("Question #3_2") {
    execute_test("test_3_2.in", test_2);
}

TEST_CASE("Question #3_3") {
    execute_test("test_3_1.in", test_3);
}

TEST_CASE("Question #3_4") {
    execute_test("test_3_2.in", test_4);
}