//
// Created by nueck on 23-11-23.
//
#include <iostream>
#include <future>

// 一个简单的函数，用于演示异步执行
int add(int a, int b) {
    std::cout << "Adding numbers asynchronously..." << std::endl;
    return a + b;
}

int main() {
    // 启动异步任务，将 add 函数异步执行，并返回与该异步任务关联的 std::future 对象
    std::future<int> futureResult = std::async(add, 3, 4);

    // 这里可以执行主线程的其他工作

    // 获取异步任务的结果，这会阻塞主线程，直到异步任务完成
    int result = futureResult.get();

    std::cout << "Result: " << result << std::endl;

    return 0;
}