//
// Created by Nueck on 2023/11/24.
//
#include <iostream>

class Example {
public:
    int x;
    const double pi;
    int &ref;

    // 构造函数的初始化列表
    Example(int a, double b, int &r) : x(a), pi(b), ref(r) {
        // 构造函数体
        // 在这里可以进行其他的初始化或逻辑操作
    }

    void printValues() const {
        std::cout << "x: " << x << ", pi: " << pi << ", ref: " << ref << std::endl;
    }
};

int main() {
    int variable = 42;
    Example example(10, 3.14, variable);

    example.printValues();

    return 0;
}
