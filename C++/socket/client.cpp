//
// Created by Nueck on 2023/11/24.
//
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // 创建socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    // 设置服务器地址结构
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);  // 使用8080端口
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  // 服务器IP地址

    // 连接到服务器
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(clientSocket);
        return -1;
    }

    std::cout << "Connected to server\n";

    // 在这里可以进行数据的收发操作

    // 关闭连接
    close(clientSocket);

    return 0;
}
