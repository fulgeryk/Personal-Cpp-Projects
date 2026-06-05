#include "Server.hpp"

Server::Server()
{
    running_ = false;
}
Server::~Server()
{
    stop();
}
void Server::bindSocket()
{
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port_);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int bindSock = ::bind(serverSocket_.fd(), reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (bindSock == -1)
    {
        throw std::runtime_error(
            std::string("[ERROR-Server] Error while bind socket: ") + strerror(errno)
        );
    }
    std::cout << "[INFO-Server] Bind  success created\n";
}
void Server::listenSocket(int backlog)
{
    int listenSock = ::listen(serverSocket_.fd(), backlog);
    if (listenSock == -1)
    {
        throw std::runtime_error(
            std::string("[ERROR-Server] Error listen socket: ") + strerror(errno)
        );
    }
    std::cout << "[INFO-Server] Listen with success \n";
}
void Server::addClient(int clientSocket)
{
    std::lock_guard<std::mutex> lock(clientsMutex_);
    auto client = std::make_unique<Socket>(clientSocket);
    connectedClients_.push_back(std::move(client));
}
void Server::removeClient(int clientSocket)
{
    std::lock_guard<std::mutex> lock(clientsMutex_);
    for(size_t i = 0; i < connectedClients_.size(); ++i)
    {
        if(connectedClients_[i]->fd() == clientSocket)
        {
            connectedClients_.erase(connectedClients_.begin() + i);
            return;
        }
    }
}
void Server::handleClient(int clientSocket)
{
    while(running_)
    {
        char buffer[1024];
        ssize_t bytesRecv = ::recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRecv == -1)
        {
            std::cout << "[ERROR-Server] Error receive bytes:" << strerror(errno) << "\n";
            removeClient(clientSocket);
            return;
        }
        else if (bytesRecv == 0)
        {
            std::cout << "[INFO-Server] Client disconnected unexpectedly. Socket: " <<clientSocket << "\n";
            removeClient(clientSocket);
            return;
        }
        std::cout << "[INFO-Server] Bytes receives with success \n";
        std::string messageReceived(buffer, bytesRecv);
        if(messageReceived == "/exit")
        {
            std::cout << "[INFO-Server] Client disconnected. Socket: " << clientSocket << "\n";
            removeClient(clientSocket);
            return;
        }
        std::cout << "Message from client: " << messageReceived << std::endl;
        broadcastMessage(clientSocket, messageReceived);
    }    
}
void Server::broadcastMessage(int senderSocket, const std::string& message)
{
    std::lock_guard<std::mutex> lock(clientsMutex_);
    for(size_t i = 0; i < connectedClients_.size(); ++i)
    {
        if(connectedClients_[i]->fd() != senderSocket)
        {
            ssize_t bytesSentServer = connectedClients_[i]->send(message.c_str(), message.size(), 0);
            if (bytesSentServer == -1)
            {
                std::cout << "[ERROR-Server] Error while sending message:" << strerror(errno) << "\n";
                continue;
            }
            if (bytesSentServer != static_cast<ssize_t>(message.size()))
            {
                std::cout << "[WARN-Server] Not all bytes were sent\n";
            }
        }
    }
}
void Server::acceptClients()
{
    while(running_)
    {
        int acceptSock = ::accept(serverSocket_.fd(), nullptr, nullptr);
        if (acceptSock == -1)
        {
            if(!running_)
            {
                return;
            }
            throw std::runtime_error(
                std::string("[ERROR-Server] Error accept socket: ") + strerror(errno)
            );
        }
        std::cout << "[INFO-Server] Accept with success \n";
        addClient(acceptSock);
        std::thread clientThread(&Server::handleClient,this, acceptSock);
        clientThread.detach();
    }
}
void Server::start()
{
    running_ = true;
    bindSocket();
    listenSocket(backlog);
    acceptClients();
}
void Server::stop()
{
    running_ = false;
    serverSocket_.close();
}
