//
// Created by nueck on 23-11-18.
//
#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> multipleReturns() {
    int intValue = 42;
    double doubleValue = 3.14;
    std::string stringValue = "Hello, Tuple!";

    // 将多个值打包成元组并返回
    return std::make_tuple(intValue, doubleValue, stringValue);
}

int main() {
    // 调用函数获取多个返回值
    auto result = multipleReturns();

    // 从元组中解包多个返回值
    int intValue;
    double doubleValue;
    std::string stringValue;

    std::tie(intValue, doubleValue, stringValue) = result;

    // 输出结果
    std::cout << "Int value: " << intValue << std::endl;
    std::cout << "Double value: " << doubleValue << std::endl;
    std::cout << "String value: " << stringValue << std::endl;

    return 0;
}
