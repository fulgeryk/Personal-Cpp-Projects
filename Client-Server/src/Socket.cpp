#include "Socket.hpp"

Socket::Socket()
{
    fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd_ == -1)
    {
        throw std::runtime_error(
            std::string("Failed to create socket: ") + strerror(errno)
        );
    }
    std::cout << "[INFO-Socket] Socket created\n";
}
Socket::Socket(int fd) : fd_{fd} {}
ssize_t Socket::send(const void* buffer, size_t length, int flags)
{
    return ::send(fd_, buffer, length, flags);
}
ssize_t Socket::recv(void* buffer, size_t length, int flags)
{
    return ::recv(fd_, buffer, length, flags);
}
void Socket::close()
{
    if(fd_ != -1)
    {
        ::close(fd_);
        fd_ = -1;
    }
}
int Socket::fd() const
{
    return fd_;
}
Socket::Socket(Socket&& other) noexcept
{
    fd_ = other.fd_;
    other.fd_ = -1;
}
Socket& Socket::operator=(Socket&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }
    close();
    fd_ = other.fd_;
    other.fd_ = -1;
    return *this;
}
Socket::~Socket()
{
    close();
}
