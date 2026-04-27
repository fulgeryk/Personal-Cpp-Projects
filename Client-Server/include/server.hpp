#include <iostream>
#include <cstring>   // strerror
#include <cerrno>    // errno
#include <sys/socket.h> //socket, bind, listen, accept
#include <netinet/in.h> // IP + port
#include <arpa/inet.h> // IPs (ex: "127.0.0.1")
#include <unistd.h> //System (close)
#include <chrono>

namespace server
{
    std::string responseMessage(const char* message, size_t count);
    std::string currentTimeString();
}
