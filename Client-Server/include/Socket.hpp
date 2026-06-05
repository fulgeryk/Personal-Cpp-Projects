#include "SocketIf.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <cerrno>
#include <iostream>
#include <stdexcept>
#include <cstring>

class Socket : public SocketIf{
public:
    Socket();
    explicit Socket(int fd);
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    Socket(Socket&&) noexcept;
    Socket& operator=(Socket&&) noexcept;
    ssize_t send(const void* buffer, size_t length, int flags) override;
    ssize_t recv(void* buffer, size_t length, int flags) override;
    void close() override;
    int fd() const override;
    ~Socket() override;
private:
    int fd_{-1};
};