#include "Server.h"

Server::Server() {
    char buffer[bufferSize];
    this->buffer = buffer;
    setup();
}

Server::Server(int portNumber) {
    this->portNumber = portNumber;
    char buffer[bufferSize];
    this->buffer = buffer;
    setup();
}

Server::Server(int portNumber, int bufferSize) {
    this->portNumber = portNumber;
    char buffer[bufferSize];
    this->buffer = buffer;
    setup();
}

void Server::setup() {
    this->client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        std::cout << "\nError establishing socket..." << std::endl;
        exit(1);
    }

    std::cout << "\n=> Socket server has been created..." << std::endl;

    this->server_address.sin_family = AF_INET;
    this->server_address.sin_addr.s_addr = htons(INADDR_ANY);
    this->server_address.sin_port = htons(this->portNumber);

    if ((bind(client, (struct sockaddr*)&server_address,sizeof(server_address))) < 0) {
        std::cout << "=> Error binding connection, the socket has already been established..." << std::endl;
        exit(-1);
    }
}

void Server::start() {

    this->size = sizeof(server_address);
    std::cout << "=> Looking for clients..." << std::endl;
    listen(client, 15);

    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_address,&size);

    if (server < 0)
        std::cout << "=> Error on accepting..." << std::endl;

    while (server > 0) {
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufferSize, 0);
        std::cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << std::endl;
        std::cout << "\n=> Enter # to end the connection\n" << std::endl;

        std::cout << "Client: ";
        do {
            recv(server, buffer, bufferSize, 0);
            std::cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        do {
            std::cout << "\nServer: ";
            do {
                std::cin >> buffer;
                send(server, buffer, bufferSize, 0);
                if (*buffer == '#') {
                    send(server, buffer, bufferSize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');

            std::cout << "Client: ";
            do {
                recv(server, buffer, bufferSize, 0);
                std::cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    isExit = true;
                }
            } while (*buffer != '*');
        } while (!isExit);

        std::cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_address.sin_addr);
        close(server);
        std::cout << "\nGoodbye..." << std::endl;
        isExit = false;
        exit(1);
    }

    close(client);

}

