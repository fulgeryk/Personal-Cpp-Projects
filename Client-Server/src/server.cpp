#include <iostream>
#include <cstring>   // strerror
#include <cerrno>    // errno
#include <sys/socket.h> //socket, bind, listen, accept
#include <netinet/in.h> // IP + port
#include <arpa/inet.h> // IPs (ex: "127.0.0.1")
#include <unistd.h> //System (close)

int main()
{
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "[INFO-Server] Socket created\n";
    if (serverSock == -1)
    {
        std::cout << " [ERROR-Server] Error while creating socket: " << strerror(errno) << "\n";
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5050);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int bindSock = bind(serverSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (bindSock == -1)
    {
        std::cout << "[ERROR-Server] Error while bind socket:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Server] Bind  success created\n";
    
    int listenSock = listen(serverSock, 10);
    if (listenSock == -1)
    {
        std::cout << "[ERROR-Server] Error listen socket:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Server] Listen with success \n";

    int acceptSock = accept(serverSock, nullptr, nullptr);
    if (acceptSock == -1)
    {
        std::cout << "[ERROR-Server] Error accept socket:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Server] Accept with success \n";

    char buffer[1024];
    ssize_t bytesRecv = recv(acceptSock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRecv == -1)
    {
        std::cout << "[ERROR-Server] Error receive bytes:" << strerror(errno) << "\n";
        return 1;
    }
    std::cout << "[INFO-Server] Bytes receives with success \n";

    std::cout << "Message from client: " << buffer << std::endl;
    close(serverSock);
    std::cout << "[INFO-Server] Socket closed\n";
    return 0;
}

