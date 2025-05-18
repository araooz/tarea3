//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include <iterator>
#include <vector>
#include <utility>
#include "p9.h"
using namespace std;

static void test_1() {
    fixed_stack<int, 5> fs1 {1, 2, 3, 4, 5};
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }
}

static void test_2() {
    fixed_stack<int, 100> fs1;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), fixed_stack_pusher(fs1));
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }
}

static void test_3() {
    fixed_stack<float, 100> fs1;
    vector<float> vc1{istream_iterator<float>(cin), istream_iterator<float>()};
    for(const auto& item: vc1)
        fs1.push(item);
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }
}

static void test_4() {
    fixed_stack<float, 5> fs1;
    vector<float> vc1{istream_iterator<float>(cin), istream_iterator<float>()};
    for(const auto& item: vc1)
        if (!fs1.push(item))
            break;
    while (!fs1.empty()) {
        cout << fs1.top() << " ";
        fs1.pop();
    }
}

static void test_5() {
    fixed_stack<unique_ptr<pair<int, int>>, 7> fs1;
    int n = 0;
    cin >> n;
    vector<pair<int, int>> vc1(n);
    for (auto& item: vc1)
        cin >> item.first >> item.second;

    for (auto& item: vc1)
       if (!fs1.push(make_unique<pair<int, int>>(item)))
            break;

    while (!fs1.empty()){
        cout << fs1.top()->first << " " << fs1.top()->second << std::endl;
        fs1.pop();
    }
}

TEST_CASE("Question #9_1") {
    execute_test("test_9_1.in", test_1);
}

TEST_CASE("Question #9_2") {
    execute_test("test_9_2.in", test_2);
}

TEST_CASE("Question #9_3") {
    execute_test("test_9_3.in", test_3);
}

TEST_CASE("Question #9_4") {
    execute_test("test_9_4.in", test_4);
}

TEST_CASE("Question #9_5") {
    execute_test("test_9_5.in", test_5);
}