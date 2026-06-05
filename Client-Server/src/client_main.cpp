#include "Client.hpp"

int main()
{
    try
    {
        Client client;
        client.start();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
        return 1;
    }

    return 0;
}