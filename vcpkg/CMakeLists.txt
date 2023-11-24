cmake_minimum_required(VERSION 3.26)
project(vcpkg)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(vcpkg main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

find_package(Boost REQUIRED COMPONENTS json serialization)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost Boost::json Boost::serialization)



