//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p2.h"
#include <list>
#include <forward_list>
using namespace std;

static void test_1() {
    stringstream os;
    list<int> l1 = { 10, 20, 30, 40, 50, 60, 70 };
    list<int> l2 = { 4, 8 };
    auto res1 = sum_range(l1, l2);
    for (const auto& item : res1)
        cout << item << " ";
}

static void test_2() {
    forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
    forward_list<int> fl2 = { 4, 8, 7};
    auto res2 = sum_range(fl1, fl2);
    for (const auto& item : res2)
        cout << item << " ";

}

TEST_CASE("Question #2_1") {
    execute_test("test_2_1.in", test_1);
}

TEST_CASE("Question #2_2") {
    execute_test("test_2_2.in", test_2);
}