#include <iostream>
#include <cstring>   // strerror
#include <cerrno>    // errno
#include <sys/socket.h> //socket, bind, listen, accept
#include <netinet/in.h> // IP + port
#include <arpa/inet.h> // IPs (ex: "127.0.0.1")
#include <unistd.h> //System (close)
#include <string>

int main()
{
    int clientSock = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "[INFO-Client] Socket created\n";
    if (clientSock == -1)
    {
        std::cout << " [ERROR-Client] Error while creating socket: " << strerror(errno) << "\n";
        return 1;
    }

    struct sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5050);
    serverAddr.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    int connectSock = connect(clientSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (connectSock == -1)
    {
        std::cout << "[ERROR-Client] Error while bind socket:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Client] Client connected with success\n";

    std::string message = "Work on server !";
    ssize_t bytesSent = send(clientSock, message.c_str(), message.size(), 0);
    if (bytesSent == -1)
    {
        std::cout << "[ERROR-Client] Error while sending message:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Client] Send message with success \n";
    close(clientSock);
    return 0;
}