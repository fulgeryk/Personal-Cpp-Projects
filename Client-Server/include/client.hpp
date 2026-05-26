#include <iostream>
#include <cstring>      // strerror
#include <cerrno>       // errno
#include <sys/socket.h> //socket, bind, listen, accept
#include <netinet/in.h> // IP + port
#include <arpa/inet.h>  // IPs (ex: "127.0.0.1")
#include <unistd.h>     //System (close)
#include <string>
#include <thread>

constexpr auto ip_raspberry{"192.168.1.134"};

namespace client
{
    void receiveMessages(int clientSock);
}
