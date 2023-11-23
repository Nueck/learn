//
// Created by nueck on 23-11-23.
//
#include <iostream>
#include <boost/coroutine2/all.hpp>
#include <boost/asio.hpp>

// 使用 boost::coroutines2::coroutine 作为协程
using Coroutine = boost::coroutines2::coroutine<int>;

// 定义一个简单的协程函数
void simpleCoroutine(Coroutine::push_type& yield) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Coroutine Yielding: " << i << std::endl;
        yield(i);  // 通过 yield 将值传递给调用者
    }
}

int main() {
    // 使用 boost::asio::io_context 运行异步操作
    boost::asio::io_context ioContext;

    // 创建协程对象
    Coroutine::pull_type coroutine(simpleCoroutine);

    // 异步执行协程
    boost::asio::post(ioContext, [&coroutine]() {
        // 从协程中获取值
        while (coroutine) {
            int value = coroutine.get();  // 获取协程产生的值
            std::cout << "Main Function Receiving: " << value << std::endl;

            coroutine();  // 继续执行协程
        }
    });

    // 在 io_context 上运行异步操作
    ioContext.run();

    return 0;
}
