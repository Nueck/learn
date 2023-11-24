//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // 插入元素
    myVector.push_back(3);
    myVector.push_back(1);
    myVector.push_back(2);

    // 遍历输出
    for (const auto &value: myVector) {
        std::cout << value << " ";
    }

    return 0;
}
