//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p5.h"
#include <tuple>
#include <iomanip>
#include <string>
using namespace std;

static void test_1() {
    std::tuple<int, string, string, double> t1 = { 1321, "Jose", "Perez", 1.68 };
    int key; string first_name; string last_name; double height;
    unpack(key, first_name, last_name, height) = t1;
    cout << key << " " << first_name << " " << last_name << " " << height;
}


static void test_2() {
    std::tuple<string, string, char> t1 = { "Texto1", "Texto2", 'A' };
    string text1; string text2; char flag;
    unpack(text1, text2, flag) = t1;
    cout << text1 << " " << text2 << " " << flag;
}

TEST_CASE("Question #5_1") {
    execute_test("test_5_1.in", test_1);
}

TEST_CASE("Question #5_2") {
    execute_test("test_5_2.in", test_2);
}