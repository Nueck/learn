
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::queue<std::string> messages;
std::condition_variable cv;

// 写入消息的线程函数
void writerThread() {
    // 模拟产生一些消息
    for (int i = 0; i < 100; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            messages.push("Message " + std::to_string(i));
        }
        cv.notify_one();  // 通知读取线程有新消息

        std::this_thread::sleep_for(std::chrono::seconds(1));  // 等待一秒钟
    }
}

// 读取消息的线程函数
void readerThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !messages.empty(); });  // 等待有新消息
        std::string message = messages.front();
        messages.pop();
        lock.unlock();

        // 处理消息
        std::cout << "Received: " << message << std::endl;
    }
}

int main() {
    // 启动写入消息的线程
    std::thread writer(writerThread);

    // 启动读取消息的线程
    std::thread reader(readerThread);

    // 等待线程结束
    writer.join();
    reader.join();

    return 0;
}