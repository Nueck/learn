//
// Created by nueck on 23-11-18.
//
#include <iostream>
#include <tuple>

using namespace std;

tuple<int, double, std::string> multipleReturns() {
    int intValue = 42;
    double doubleValue = 3.14;
    std::string stringValue = "Hello, Tuple!";

    // 将多个值打包成元组并返回
    return {intValue, doubleValue, stringValue};
}

tuple<int, double> func() {
    return {1, 2.2};
}


int main() {
    // 调用函数获取多个返回值
    auto result = multipleReturns();

    auto[intValue,doubleValue,stringValue]= result;

    auto[i, d] = func(); //是C++11的tie吗？更高级
    std::cout << i << std::endl;
    std::cout << d << std::endl;

    // 输出结果
    std::cout << "Int value: " << intValue << std::endl;
    std::cout << "Double value: " << doubleValue << std::endl;
    std::cout << "String value: " << stringValue << std::endl;

    return 0;
}
