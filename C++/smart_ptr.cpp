//
// Created by nueck on 23-11-23.
//
#include <iostream>
#include <memory>

class MyClass {
public:

    //explicit 是C++中的关键字，通常用于修饰类构造函数，以防止隐式转换。
    //使用 explicit 关键字可以防止编译器执行某些类型的自动转换，强制要求显式调用构造函数。
    explicit MyClass(int value) : data(value) {
        std::cout << "构造函数: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "析构函数: " << data << std::endl;
    }

    void printData() const {
        std::cout << "数据: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // 使用 std::unique_ptr
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));

    // 访问对象的成员函数
    uniquePtr->printData();

    // std::unique_ptr 会在超出其作用域时自动释放对象

    // 使用 std::shared_ptr
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(55);

    // 访问对象的成员函数
    sharedPtr->printData();

    // std::shared_ptr 会在最后一个引用它的 shared_ptr 被销毁时自动释放对象

    // 使用 std::weak_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // std::weak_ptr 不会增加引用计数，
    // 因此对象不会仅因为 weakPtr 的存在而保持存活

    // 要使用 weak_ptr，需要通过 lock() 获取一个 shared_ptr
    if (auto sharedPtrFromWeak = weakPtr.lock()) {
        // 访问对象的成员函数
        sharedPtrFromWeak->printData();
    } else {
        std::cout << "对象已不可用。" << std::endl;
    }

    // 使用 shared_ptr 或 weak_ptr 时不需要手动释放对象

    return 0;
}
