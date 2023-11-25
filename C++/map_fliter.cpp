//
// Created by nueck on 23-11-24.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 std::transform 将每个元素加倍
    std::vector<int> doubledNumbers;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(doubledNumbers), [](int x) { return x * 2; });

    // 输出加倍后的结果
    for (int num : doubledNumbers) {
        std::cout << num << " ";
    }

    return 0;
}
