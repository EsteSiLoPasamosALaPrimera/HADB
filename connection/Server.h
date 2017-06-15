#ifndef PRACTICE_SEVER_H
#define PRACTICE_SEVER_H

#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server {
private:
    int client;
    int server;
    int portNumber = 1500;
    bool isExit = false;
    int bufferSize = 1024;
    char* buffer;
    struct sockaddr_in server_address;
    socklen_t size;
    void setup();
public:
    Server();
    Server(int portNumber);
    Server(int portNumber, int bufsize);
    void start();
};


#endif //PRACTICE_SEVER_H
