#pragma once
#include <mutex>
#include <vector>

class ServerIf{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~ServerIf() = default;
};
