#include "Server.hpp"

int main()
{
    try
    {
        Server server;
        server.start();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
        return 1;
    }
    return 0;
}