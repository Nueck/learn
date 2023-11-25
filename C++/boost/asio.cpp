//
// Created by nueck on 23-11-23.
//
#include <iostream>
#include <coroutine>
#include <boost/asio.hpp>
#include <boost/asio/use_awaitable.hpp>

namespace asio = boost::asio;

class CoroutineData {
public:
    std::string message;
};

class CoroutineWithMainThreadInteraction {
public:
    struct promise_type;

    // 协程句柄
    std::coroutine_handle<promise_type> handle;

    // 构造函数
    explicit CoroutineWithMainThreadInteraction(std::coroutine_handle<promise_type> h) : handle(h) {}

    // 析构函数
    ~CoroutineWithMainThreadInteraction() {
        if (handle) handle.destroy();
    }

    // 恢复协程执行
    void resume() {
        handle.resume();
    }

    // 协程的 promise 类型
    struct promise_type {
        CoroutineWithMainThreadInteraction get_return_object() {
            return CoroutineWithMainThreadInteraction{
                    std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        asio::awaitable<void> initial_suspend() {
            std::cout << "CoroutineWithMainThreadInteraction Started" << std::endl;
            co_await asio::suspend_never{};
        }

        asio::awaitable<void> final_suspend() noexcept {
            std::cout << "CoroutineWithMainThreadInteraction Finished" << std::endl;
            co_await asio::suspend_never{};
        }

        void return_void() {}

        // 向主线程发送消息
        void sendToMainThread(const std::string& msg) {
            asio::post(mainIoContext, [this, msg]() {
                std::cout << "Message from CoroutineWithMainThreadInteraction: " << msg << std::endl;
            });
        }

        // 接收主线程的消息
        asio::awaitable<std::string> receiveFromMainThread() {
            co_return "Hello from the main thread!";
        }

        void unhandled_exception() {
            std::terminate();
        }
    };
};

// 主线程使用的 io_context
asio::io_context mainIoContext;

// 协程和主线程之间的异步通信
asio::awaitable<void> communicationBetweenCoroutineAndMainThread() {
    CoroutineWithMainThreadInteraction coroutine = CoroutineWithMainThreadInteraction::promise_type{}.get_return_object();

    // 执行协程，与主线程进行数据交互
    coroutine.resume();
    coroutine.handle.promise().sendToMainThread("Hello from CoroutineWithMainThreadInteraction!");

    // 接收来自协程的消息
    std::string messageFromCoroutine = co_await coroutine.handle.promise().receiveFromMainThread();
    std::cout << "Message received in the main thread: " << messageFromCoroutine << std::endl;
}

int main() {
    asio::co_spawn(mainIoContext, communicationBetweenCoroutineAndMainThread(), asio::detached);

    // 在主线程运行事件循环
    mainIoContext.run();

    return 0;
}
