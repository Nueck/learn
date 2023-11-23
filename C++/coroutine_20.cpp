//
// Created by nueck on 23-11-23.
//必须添加-std=c++20才能启用c++20
// g++ -std=c++20 -o my_program my_program.cpp
#include <iostream>
#include <coroutine>

// 定义一个简单的协程
struct SimpleCoroutine {
    struct promise_type {
        SimpleCoroutine get_return_object() {
            return SimpleCoroutine(std::coroutine_handle<promise_type>::from_promise(*this));
        }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    SimpleCoroutine(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~SimpleCoroutine() {
        if (handle) handle.destroy();
    }

    // 协程的执行逻辑
    void resume() {
        handle.resume();
    }

private:
    std::coroutine_handle<promise_type> handle;
};

// 协程函数
SimpleCoroutine simpleCoroutine() {
    std::cout << "Coroutine Started" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Coroutine Resumed" << std::endl;
}

int main() {
    SimpleCoroutine coroutine = simpleCoroutine();

    // 执行协程
    coroutine.resume();

    std::cout << "Main Function" << std::endl;

    // 由于使用了 RAII，协程会在 SimpleCoroutine 对象销毁时正常结束
    return 0;
}
