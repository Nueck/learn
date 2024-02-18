```
#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <any>

//using VariantType = std::variant<int, double, std::string>;
//如何获取index
using VariantType =  std::any;

template<typename T>
void process_data(std::vector<VariantType> &vec, const T& data) {
    std::cout << "Processing data: " << data << std::endl;
    vec.push_back(data);
}

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

template<typename... Args>
void register_audio_handler(const std::string& str, const std::function<std::string(const std::string&)>& func, Args... args) {
    // 创建一个 vector 存储 VariantType
    std::vector<VariantType> vec;

    // 调用 process_data 函数，传递可变参数 args
    (process_data(vec,args), ...);


    for (const auto& element : vec) {
        try {
            if (element.type() == typeid(int)) {
                std::cout << "Value(int): " << std::any_cast<int>(element) << std::endl;
            } else if (element.type() == typeid(double)) {
                std::cout << "Value(double): " << std::any_cast<double>(element) << std::endl;
            } else if (element.type() == typeid(const char*)) {
                std::cout << "Value(char): " << std::any_cast<const char*>(element) << std::endl;
            } else {
                std::cout << "Unknown type" << std::endl;
            }
        } catch (const std::bad_any_cast& e) {
            std::cout << "Caught bad_any_cast: " << e.what() << std::endl;
        }
    }



    std::cout << "String parameter: " << str  << std::endl;


    // 调用 lambda 函数
    std::cout << func(str)<< " invoked" << std::endl;

}

int main() {
    // 使用 lambda 函数作为示例函数参数
    auto multiply = [](const std::string& y) { return y + " hello"; };

    // 调用 register_audio_handler 函数，传递两个不同的函数和它们的参数
    register_audio_handler("打开按钮", multiply, 5, 10,"str"); // 调用带有多个参数的函数

    std::cout << "Hello, World!" << std::endl;
    return 0;
}


```
