//
// Created by Nueck on 2023/11/23.
//
#include <iostream>
#include <thread>
#include <chrono>

// 简单的任务函数，打印一些信息
void taskFunction(int id) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << id << ": Working... " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // 创建两个线程并启动它们，每个线程执行 taskFunction
    std::thread thread1(taskFunction, 1);
    std::thread thread2(taskFunction, 2);

    // 主线程等待两个线程完成
    thread1.join();
    thread2.join();

    std::cout << "All threads have finished execution." << std::endl;

    return 0;
}
