//
// Created by Nueck on 2023/11/23.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// 使用istringstream和getline函数实现字符串分割
std::vector<std::string> splitString(const std::string &input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    // 例子字符串
    std::string inputString = "apple orange banana";

    // 分割字符串
    std::vector<std::string> words = splitString(inputString, ' ');

    // 判断是否包含字符'a'
    for (const std::string &word : words) {
        if (word.find('a') != std::string::npos) {
            std::cout << "字符串 '" << word << "' 包含字符 'a'" << std::endl;
        } else {
            std::cout << "字符串 '" << word << "' 不包含字符 'a'" << std::endl;
        }
    }

    return 0;
}
