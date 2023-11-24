//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <optional>

std::shared_mutex mySharedMutex;

void readFunction(int id) {
    std::shared_lock<std::shared_mutex> lock(mySharedMutex);
    std::cout << "Thread " << id << " is reading." << std::endl;
    // 读取操作
}

void writeFunction(int id) {
    std::unique_lock<std::shared_mutex> lock(mySharedMutex);
    std::cout << "Thread " << id << " is writing." << std::endl;
    // 写入操作
}

int main() {
    
    // 创建多个读取线程和一个写入线程
    std::thread reader1(readFunction, 1);
    std::thread reader2(readFunction, 2);
    std::thread writer(writeFunction, 3);

    // 等待线程完成
    reader1.join();
    reader2.join();
    writer.join();

    return 0;
}
