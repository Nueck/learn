//
// Created by nueck on 23-11-17.
//

#include "multi_pipe.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<std::string> messages;

// 写入消息的线程函数
void writerThread() {
    for (int i = 0; i < 5; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            messages.push("Message " + std::to_string(i));
        }
        cv.notify_all();  // 通知所有等待的线程
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}

// 读取消息的线程函数
void readerThread(int threadID) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !messages.empty(); });

        // 检查条件，确保只有特定的线程能够处理消息
        if (threadID == 1) {
            std::string message = messages.front();
            messages.pop();
            lock.unlock();

            // 处理消息
            std::cout << "Thread " << threadID << " Received: " << message << std::endl;
        } else {
            // 如果不是目标线程，继续等待
            lock.unlock();
        }
    }
}

int main() {
    std::thread writer(writerThread);
    std::thread reader1(readerThread, 1);
    std::thread reader2(readerThread, 2);

    writer.join();
    reader1.join();
    reader2.join();

    return 0;
}