//
// Created by nueck on 23-11-18.
//
#include <iostream>

// 通过指针修改参数的值
void modifyWithPointer(int* x) {
    (*x)++;
}

// 通过引用修改参数的值
void modifyWithReference(int& x) {
    x++;
}

int main() {
    int value = 10;

    // 通过指针传递
    modifyWithPointer(&value);
    std::cout << "After modifyWithPointer: " << value << std::endl;

    // 重新初始化 value
    value = 10;

    // 通过引用传递
    modifyWithReference: " << value << std::endl;

    return 0;
}
