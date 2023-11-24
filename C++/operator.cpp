//
// Created by Nueck on 2023/11/24.
//
#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r, double i) : real(r), imag(i) {}

    // 1. 重载比较运算符
    bool operator==(const Complex &other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // 2. 重载算术运算符
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 3. 重载赋值运算符
    Complex &operator=(const Complex &other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // 4. 重载流运算符
    friend std::ostream &operator<<(std::ostream &os, const Complex &obj) {
        os << obj.real << " + " << obj.imag << "i";
        return os;
    }

    // 5. 重载函数调用运算符
    double operator()(double x, double y) const {
        return real * x + imag * y;
    }

    // 6. 重载下标运算符
    double &operator[](int index) {
        if (index == 0) return real;
        else if (index == 1) return imag;
        else throw std::out_of_range("Invalid index");
    }
};

int main() {
    // 创建两个复数对象
    Complex c1(2.0, 3.0);
    Complex c2(1.0, 4.0);

    // 1. 使用重载的比较运算符
    if (c1 == c2) {
        std::cout << "c1 is equal to c2" << std::endl;
    } else {
        std::cout << "c1 is not equal to c2" << std::endl;
    }

    // 2. 使用重载的算术运算符
    Complex result = c1 + c2;
    std::cout << "c1 + c2 = " << result << std::endl;

    // 3. 使用重载的赋值运算符
    Complex c3(0.0, 0.0);
    c3 = c1;
    std::cout << "c3 = " << c3 << std::endl;

    // 4. 使用重载的流运算符
    std::cout << "c1: " << c1 << std::endl;

    // 5. 使用重载的函数调用运算符
    double resultFunction = c1(2.0, 3.0);
    std::cout << "c1(2.0, 3.0) = " << resultFunction << std::endl;

    // 6. 使用重载的下标运算符
    std::cout << "c1[0] = " << c1[0] << ", c1[1] = " << c1[1] << std::endl;

    return 0;
}
