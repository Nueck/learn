//
// Created by Nueck on 2023/11/23.
//
#include <iostream>
#include <regex>

int main() {
    // 例子字符串
    std::string inputString = "apple orange banana";

    // 正则表达式模式
    std::regex pattern("a");


    std::regex  pattern1("apple");

    // 使用std::regex_search进行匹配
    if (std::regex_search(inputString,pattern1)) {
        std::cout << "字符串中包含字符 'a'" << std::endl;
    } else {
        std::cout << "字符串中不包含字符 'a'" << std::endl;
    }

    return 0;
}
