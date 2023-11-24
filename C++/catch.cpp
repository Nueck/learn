//
// Created by Nueck on 2023/11/23.
//
#include <iostream>

int main() {

    #include <stdexcept>
    try {
        // 试图执行可能引发异常的代码块
        int numerator, denominator, result;

        std::cout << "输入分子: ";
        std::cin >> numerator;

        std::cout << "输入分母: ";
        std::cin >> denominator;

        if (denominator == 0) {
            // 如果分母为零，抛出一个异常
            throw std::runtime_error("分母不能为零");
        }

        result = numerator / denominator;

        // 如果没有异常，输出结果
        std::cout << "结果: " << result << std::endl;
    } catch (const std::exception& e ) {
        // 捕获异常并处理
        std::cerr << "发生异常: " << e.what() << std::endl;
    }

    return 0;
}