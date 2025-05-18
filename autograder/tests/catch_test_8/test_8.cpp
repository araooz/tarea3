//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "p8.h"
#include <string>
using namespace std;

static void test_1() {
    string file_name;
    char key;
    cin >> file_name >> key;
    for(const auto& code: filter_codes(file_name, key))
        cout << code << " ";
}

TEST_CASE("Question #8") {
    execute_test("test_8_1.in", test_1);
}