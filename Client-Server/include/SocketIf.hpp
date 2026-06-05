#pragma once
#include <cstddef>
#include <sys/types.h>

class SocketIf{
public:
    virtual ssize_t send(const void* buffer, size_t length, int flags) = 0;
    virtual ssize_t recv(void* buffer, size_t length, int flags) = 0;
    virtual void close() = 0;
    virtual int fd() const = 0;
    virtual ~SocketIf() = default;
};