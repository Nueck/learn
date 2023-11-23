//
// Created by nueck on 23-11-23.
//
#include <thread>
#include <iostream>
#include <future>
#include <chrono>

// 一个简单的函数，用于演示异步执行
int add(int a, int b) {
    std::cout << "Adding numbers asynchronously..." << std::endl;
    // 模拟一个耗时操作
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() {
    try {
        // 启动异步任务，将 add 函数异步执行，并返回与该异步任务关联的 std::future 对象
        std::future<int> futureResult = std::async(add, 3, 4);

        // 在调用 get 之前执行其他任务
        std::cout << "Main thread doing other work..." << std::endl;

        // 模拟一个错误，导致异步任务失败
//        throw std::runtime_error("Simulated error in main thread");

        // 获取异步任务的结果，这会捕获到在其他任务期间引发的异常
        int result = futureResult.get();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

