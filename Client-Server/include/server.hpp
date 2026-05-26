#include <iostream>
#include <cstring>      // strerror
#include <cerrno>       // errno
#include <sys/socket.h> //socket, bind, listen, accept
#include <netinet/in.h> // IP + port
#include <arpa/inet.h>  // IPs (ex: "127.0.0.1")
#include <unistd.h>     //System (close)
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>

namespace server
{
    // std::string responseMessage(const char* message, size_t count);
    // std::string currentTimeString();
    void handleClient(int clientSocket);
    void addClient(int clientSocket);
    void removeClient(int clientSocket);
    void closeCommunication(int clientSocket);
    void broadcastMessage(int senderSocket, const std::string& message);
    extern std::vector<int> connectedClients;
    extern std::mutex clientsMutex;
}
