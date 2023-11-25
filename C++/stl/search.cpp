//
// Created by nueck on 23-11-24.
//
#include <algorithm>
#include <iostream>
#include <string>

int  main(){
    std::string mainString = "Hello, World!";
    std::string substring = "World";

    if (std::search(mainString.begin(), mainString.end(), substring.begin(), substring.end()) != mainString.end()) {
        std::cout << "Substring found!" << std::endl;
    } else {
        std::cout << "Substring not found!" << std::endl;
    }



}

