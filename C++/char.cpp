//
// Created by nueck on 23-11-24.
//
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s = "Hello, World!";
//
//    // 使用 std::string::const_iterator 进行遍历
//    for (char &c : s) {
//        std::cout << c << " ";
//    }
//
//    std::cout << std::endl;
//
//    // 使用范围 for 循环进行遍历
//    for (auto character : s) {
//        std::cout << character << " ";
//    }

    // 使用 std::remove_if 删除字符
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return c == 'o'; }), s.end());

    std::cout << s << std::endl;


    for (char &c : s) {
        c = 'X';  // 将每个字符修改为 'X'
    }

    std::cout << s << std::endl;  // 输出: XXXXX, XXXXX!

    return 0;

    return 0;
}
