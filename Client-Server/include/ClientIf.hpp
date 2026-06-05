#pragma once
#include <cstdint>
#include <thread>
#include <netinet/in.h>
#include <arpa/inet.h>

class ClientIf{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~ClientIf() = default;
};