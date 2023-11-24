//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <set>
#include <unordered_set>


class CustomObject {
public:
    int value;

    explicit CustomObject(int val) : value(val) {}

    // 为了使自定义对象能够在 std::set 中进行比较，需要实现比较运算符
    bool operator<(const CustomObject &other) const {
        return value < other.value;
    }
};


class CustomObject2 {
public:

    int value;

    explicit CustomObject2(int val) : value(val) {}

    bool operator==(const CustomObject2 &other) const {
        return value == other.value;
    }

    // 为了在 std::unordered_set 中进行哈希，需要提供哈希函数
    struct HashFunction {
        std::size_t operator()(const CustomObject2 &obj) const {
            return std::hash<int>()(obj.value);
        }
    };
};


int main() {
    std::set<int> mySet;

    // 插入元素
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(2);

    // 遍历输出
    for (const auto &value: mySet) {
        std::cout << value << " ";
    }

    std::unordered_set<int> myUnorderedSet;

    // 插入元素
    myUnorderedSet.insert(3);
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(2);
    myUnorderedSet.insert(3);

    // 遍历输出
    for (const auto &value: myUnorderedSet) {
        std::cout << value << " " << std::endl;
    }
    // 创建存放自定义对象的 std::set
    std::set<CustomObject> mySetObj;

    // 向 set 中插入一些对象
    mySetObj.insert(CustomObject(3));
    mySetObj.insert(CustomObject(1));
    mySetObj.insert(CustomObject(2));
    mySetObj.insert(CustomObject(3));  // 注意：std::set 存放的是唯一元素，这个会被忽略

    // 目标值
    int targetValue = 2;

    // 遍历 set，获取 value 等于目标值的对象
    for (const auto &obj: mySetObj) {
        std::cout << obj.value << std::endl;
        if (obj.value == targetValue) {
            // 找到了满足条件的对象
            std::cout << "Found object with value " << targetValue << std::endl;
            // 这里可以对找到的对象进行处理
        }
    }


    std::unordered_set<CustomObject2, CustomObject2::HashFunction> myUnorderedSetObj;

    myUnorderedSetObj.insert(CustomObject2(3));
    myUnorderedSetObj.insert(CustomObject2(2));
    myUnorderedSetObj.insert(CustomObject2(1));

    for (const auto &obj: myUnorderedSetObj) {
        if (obj.value == targetValue) {
            // 找到了满足条件的对象
            std::cout << "Found object with value " << targetValue << std::endl;
            // 这里可以对找到的对象进行处理
        }
    }


    return 0;
}
