#include "server.hpp"

namespace server
{
    std::string currentTimeString()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&t_c);
    }
    std::string responseMessage(const char* message, size_t count)
    {
        std::string msg(message, count);
        if (msg == "PING")
        {
            return "PONG";
        }
        else if (msg == "TIME")
        {
            return currentTimeString();
        }
        else if (msg == "HELLO")
        {
            return "Hello Client";
        }
        else
        {
            return "Unknown command";
        }
    }
}

int main()
{
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock == -1)
    {
        std::cout << " [ERROR-Server] Error while creating socket: " << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Server] Socket created\n";

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5050);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int bindSock = bind(serverSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (bindSock == -1)
    {
        std::cout << "[ERROR-Server] Error while bind socket:" << strerror(errno) << "\n";
        close(serverSock);
        return 1;
    }
    std::cout << "[INFO-Server] Bind  success created\n";
    
    int listenSock = listen(serverSock, 10);
    if (listenSock == -1)
    {
        std::cout << "[ERROR-Server] Error listen socket:" << strerror(errno) << "\n";
        close(serverSock);
        return 1;
    }
    std::cout << "[INFO-Server] Listen with success \n";

    int acceptSock = accept(serverSock, nullptr, nullptr);
    if (acceptSock == -1)
    {
        std::cout << "[ERROR-Server] Error accept socket:" << strerror(errno) << "\n";
        close(serverSock);
        return 1;
    }
    std::cout << "[INFO-Server] Accept with success \n";

    char buffer[1024];
    ssize_t bytesRecv = recv(acceptSock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRecv == -1)
    {
        std::cout << "[ERROR-Server] Error receive bytes:" << strerror(errno) << "\n";
        close(acceptSock);
        close(serverSock);
        return 1;
    }
    else if (bytesRecv == 0)
    {
        std::cout << "[INFO-Server] Client closed connection without send data";
        close(acceptSock);
        close(serverSock);
        return 0;
    }
    std::cout << "[INFO-Server] Bytes receives with success \n";
    std::string messageReceived(buffer, bytesRecv);
    std::cout << "Message from client: " << messageReceived << std::endl;

    std::string sendMsg = server::responseMessage(messageReceived.c_str(), messageReceived.size());
    ssize_t bytesSentServer = send(acceptSock, sendMsg.c_str(), sendMsg.size(), 0);
    if (bytesSentServer == -1)
    {
        std::cout << "[ERROR-Server] Error while sending message:" << strerror(errno) << "\n";
        close(acceptSock);
        close(serverSock);
        return 1;
    }
    if (bytesSentServer != static_cast<ssize_t>(sendMsg.size()))
    {
        std::cout << "[WARN-Server] Not all bytes were sent\n";
    }
    close(acceptSock);
    close(serverSock);
    std::cout << "[INFO-Server] Socket closed\n";
    return 0;
}
