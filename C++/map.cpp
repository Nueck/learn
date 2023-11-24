
//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<int, std::string> myMap;

    // 插入键值对
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // 遍历输出
    for (const auto &pair: myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::unordered_map<int, std::string> myUnorderedMap;

    // 插入键值对
    myUnorderedMap[1] = "One";
    myUnorderedMap[2] = "Two";
    myUnorderedMap[3] = "Three";

    // 遍历输出
    for (const auto &pair: myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
