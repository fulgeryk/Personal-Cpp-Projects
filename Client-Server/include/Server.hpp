#pragma once
#include "ServerIf.hpp"
#include "Socket.hpp"
#include <netinet/in.h>
#include <memory>
#include <thread>

constexpr uint8_t backlog{10};

class Server : public ServerIf{
public:
    Server();
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    Server(Server&&) = delete;
    Server& operator=(Server&&) = delete;
    void start() override;
    void stop() override;
    ~Server() override;
private:
    Socket serverSocket_;
    uint16_t port_{5050};
    std::vector<std::unique_ptr<Socket>> connectedClients_;
    std::mutex clientsMutex_;
    bool running_;
    void bindSocket();
    void listenSocket(int backlog);
    void acceptClients();
    void addClient(int clientSocket);
    void removeClient(int clientSocket);
    void handleClient(int clientSocket);
    void broadcastMessage(int senderSocket, const std::string& message);
};
