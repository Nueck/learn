#include <boost/process.hpp>
#include <iostream>

namespace bp = boost::process;

int main() {
    // 创建进程A，它会输出一些数据到标准输出
    bp::ipstream input_stream;
    bp::child process_a("echo Hello, Boost!", bp::std_out > input_stream);

    // 创建进程B，它从进程A的输出中读取数据
    bp::ipstream output_stream;
    bp::child process_b("wc", bp::std_in <input_stream, bp::std_out> output_stream);

    // 等待进程B完成并获取结果
    process_b.wait();
    std::string result;

    // 从output_stream读取数据
    std::getline(output_stream, result);

    // 输出结果
    std::cout << "Word count: " << result << std::endl;

    return 0;
}
