#include "Client.hpp"

Client::Client() = default;
void Client::connectToServer()
{
    struct sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port_);
    int ipResult = inet_pton(AF_INET, ip_, &serverAddr.sin_addr);
    if (ipResult <= 0)
    {
        throw std::runtime_error(
            std::string("[ERROR-Client] IP invalid: ") + strerror(errno)
        );
    }
    std::cout << "[INFO-Client] ipResult success\n";

    int connectSock = ::connect(clientSocket_.fd(), reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (connectSock == -1)
    {
        throw std::runtime_error(
            std::string("[ERROR-Client] Error while connecting: ") + strerror(errno)
        );
    }
    std::cout << "[INFO-Client] Client connected with success\n";
}
void Client::receiveMessages()
{
    while(running_)
    {
        char bufferClient[1024];
        ssize_t bytesRecvClient = clientSocket_.recv(bufferClient, sizeof(bufferClient) - 1, 0);
        if (bytesRecvClient == -1)
        {
            std::cout << "[ERROR-Client] Error receive bytes:" << strerror(errno) << "\n";
            running_ = false;
            return;
        }
        else if (bytesRecvClient == 0)
        {
            std::cout << "[INFO-Client] Server closed connection without sending data";
            running_ = false;
            return;
        }
        std::cout << "[INFO-Client] Bytes receives with success \n";
        std::string response(bufferClient, bytesRecvClient);
        std::cout << "Message from Server: " << response << std::endl;
    }
}
void Client::sendMessages()
{
    while(running_)
    {
        std::string message{};
        std::cout <<"Message: ";
        std::cin >> message;
        ssize_t bytesSent = clientSocket_.send(message.c_str(), message.size(), 0);
        if (bytesSent == -1)
        {
            std::cout << "[ERROR-Client] Error while sending message:" << strerror(errno) << "\n";
            running_ = false;
            return;
        }
        if (bytesSent != static_cast<ssize_t>(message.size()))
        {
            std::cout << "[WARN-Client] Not all bytes were sent\n";
        }
        std::cout << "[INFO-Client] Send message with success \n";
    }
}
void Client::start()
{
    running_ = true;
    connectToServer();
    receiveThread_ = std::thread(&Client::receiveMessages, this);
    sendMessages();
}
void Client::stop()
{
    running_ = false;
    clientSocket_.close();
}
Client::~Client()
{
    stop();
    if(receiveThread_.joinable())
    {
        receiveThread_.join();
    }
}