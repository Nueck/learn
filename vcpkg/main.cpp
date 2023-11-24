#include <fmt/core.h>
#include <iostream>
#include <boost/json.hpp>

int main() {

    boost::json::object obj;

    fmt::print("Hello World!\n");
    auto s = fmt::format("Hello World!,{}", 1);

    obj["12"] = "test";

    std::cout << obj;

    return 0;
}
