//
// Created by nueck on 23-11-17.
//

#include <iostream>

// 接受Lambda 表达式作为参数的函数
template <typename Function>
void executeFunction(Function func) {
    // 调用Lambda 表达式
    func();
}

int main() {
    // 定义Lambda 表达式
    auto myLambda = []() {
        std::cout << "Hello from Lambda!" << std::endl;
    };

    // 调用带有Lambda 表达式参数的函数
    executeFunction(myLambda);

    // 直接传递Lambda 表达式
    executeFunction([]() {
        std::cout << "Hello from Direct Lambda!" << std::endl;
    });

    return 0;
}