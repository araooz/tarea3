#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H


#include <initializer_list>
#include <stdexcept>
#include <utility>
template <typename T, size_t sz>
class fixed_stack_pusher;

template <typename T, size_t sz>
class fixed_stack {
private:
    T data[sz];
    size_t top_index;

public:
    fixed_stack() : top_index(0) {}

    fixed_stack(std::initializer_list<T> lst) : top_index(0) {
        for (auto& val : lst) {
            if (top_index == sz)
                break;
            data[top_index++] = val;
        }
    }

    T& top() {
        if (empty())
            throw std::out_of_range("stack vacia");
        return data[top_index - 1];
    }

    const T& top() const {
        if (empty())
            throw std::out_of_range("stack vacia");
        return data[top_index - 1];
    }

    void pop() {
        if (!empty())
            --top_index;
    }

    bool push(const T& value) {
        if (top_index == sz)
            return false;  // pila llena
        data[top_index++] = value;
        return true;
    }

    bool push(T&& value) {
        if (top_index == sz)
            return false;
        data[top_index++] = std::move(value);
        return true;
    }

    bool empty() const {
        return top_index == 0;
    }

    size_t size() const {
        return top_index;
    }

    friend class fixed_stack_pusher<T, sz>;
};

template <typename T, size_t sz>
class fixed_stack_pusher {
    fixed_stack<T, sz>& stack_ref;

public:
    explicit fixed_stack_pusher(fixed_stack<T, sz>& s) : stack_ref(s) {}

    fixed_stack_pusher& operator=(const T& val) {
        stack_ref.push(val);
        return *this;
    }

    fixed_stack_pusher& operator=(T&& val) {
        stack_ref.push(std::move(val));
        return *this;
    }

    fixed_stack_pusher& operator*() {
        return *this;
    }

    fixed_stack_pusher& operator++() {
        return *this;
    }

    fixed_stack_pusher operator++(int) {
        return *this;
    }
};


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
