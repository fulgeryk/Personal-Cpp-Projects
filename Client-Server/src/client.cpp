#include "client.hpp"

int main()
{
    int clientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSock == -1)
    {
        std::cout << " [ERROR-Client] Error while creating socket: " << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Client] Socket created\n";

    struct sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5050);
    int ipResult = inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    if (ipResult <= 0)
    {
        std::cout << "[ERROR-Client] IP invalid:" << strerror(errno) << "\n";
        close(clientSock);
        return 1;
    }
    std::cout << "[INFO-Client] ipResult success\n";

    int connectSock = connect(clientSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (connectSock == -1)
    {
        std::cout << "[ERROR-Client] Error while connecting:" << strerror(errno) << "\n";
        close(clientSock);
        return 1;
    }
    std::cout << "[INFO-Client] Client connected with success\n";

    std::string message{};
    std::cout <<"Command: ";
    std::cin >> message;
    ssize_t bytesSent = send(clientSock, message.c_str(), message.size(), 0);
    if (bytesSent == -1)
    {
        std::cout << "[ERROR-Client] Error while sending message:" << strerror(errno) << "\n";
        close(clientSock);
        return 1;
    }
    if (bytesSent != static_cast<ssize_t>(message.size()))
    {
        std::cout << "[WARN-Client] Not all bytes were sent\n";
    }

    char bufferClient[1024];
    ssize_t bytesRecvClient = recv(clientSock, bufferClient, sizeof(bufferClient) - 1, 0);
    if (bytesRecvClient == -1)
    {
        std::cout << "[ERROR-Client] Error receive bytes:" << strerror(errno) << "\n";
        close(clientSock);
        return 1;
    }
    else if (bytesRecvClient == 0)
    {
        std::cout << "[INFO-Client] Server closed connection without sending data";
        close(clientSock);
        return 0;
    }
    std::cout << "[INFO-Client] Bytes receives with success \n";
    std::string response(bufferClient, bytesRecvClient);
    std::cout << "Message from Server: " << response << std::endl;


    std::cout << "[INFO-Client] Send message with success \n";
    close(clientSock);
    return 0;
}