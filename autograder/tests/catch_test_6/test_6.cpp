//
// Created by rudri on 9/12/2020.
//

#include "catch.hpp"
#include "redirect_io.h"
#include "p6.h"
#include <list>
using namespace std;

static void test_1() {
    list<int> l1 = { 11, 12, 13 };
    list<int> l2 = { 21, 22, 23 };
    list<int> l3 = { 31, 32, 33 };
    auto r1 = zip(l1, l2, l3);
    for (const auto& row : r1) {
        for (const auto& value : row)
            cout << value << " ";
    }
}

static void test_2() {
    vector<int> v1 = { 11, 12, 13, 14, 15 };
    vector<int> v2 = { 21, 22, 23, 24, 25 };
    vector<int> v3 = { 31, 32, 33, 34, 35 };
    vector<int> v4 = { 41, 42, 43, 44, 45 };
    auto r2 = zip(v1, v2, v3, v4);
    for (const auto& row : r2) {
        for (const auto& value : row)
            cout << value << " ";
    }
}

TEST_CASE("Question #6_1") {
    execute_test("test_6_1.in", test_1);
}

TEST_CASE("Question #6_2") {
    execute_test("test_6_2.in", test_2);
}
