//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <unordered_set>

class CustomObject {
public:
    int value;

    CustomObject(int val) : value(val) {}

    // 不再需要重新定义比较运算符

    // 为了在 std::unordered_set 中进行哈希，需要提供哈希函数
    struct HashFunction {
        std::size_t operator()(const CustomObject &obj) const {
            // 这里可以根据需要定义哈希函数
            return std::hash<int>()(obj.value);
        }
    };
};

int main() {
    // 创建存放自定义对象的 std::unordered_set
    std::unordered_set<CustomObject, CustomObject::HashFunction> myUnorderedSet;

    // 向 unordered_set 中插入一些对象
    myUnorderedSet.insert(CustomObject(3));
    myUnorderedSet.insert(CustomObject(1));
    myUnorderedSet.insert(CustomObject(2));
    myUnorderedSet.insert(CustomObject(3));  // 不会被忽略

    // 目标值
    int targetValue = 2;

    // 遍历 unordered_set，获取 value 等于目标值的对象
    for (const auto &obj: myUnorderedSet) {
        if (obj.value == targetValue) {
            // 找到了满足条件的对象
            std::cout << "Found object with value " << targetValue << std::endl;
            // 这里可以对找到的对象进行处理
        }
    }

    return 0;
}
