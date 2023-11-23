//
// Created by nueck on 23-11-23.
//
#include <iostream>
#include <chrono>


//其中时间戳通常指的是从某个时间点(通常是纪元，即1970年1月1日00:00:00 UTC）开始的持续时间
int main() {
    // 获取当前时刻
    auto now = std::chrono::system_clock::now();

    // 将当前时刻转换为持续时间，即自纪元以来的时间
    auto durationSinceEpoch = now.time_since_epoch();

    // 将持续时间转换为秒数
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(durationSinceEpoch);

    // 输出时间戳
    std::cout << "Timestamp: "<<  durationSinceEpoch.count() <<"  " << seconds.count() << " seconds since epoch." << std::endl;

    return 0;
}
