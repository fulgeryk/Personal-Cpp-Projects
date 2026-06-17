#include "Engine.hpp"
#include <iostream>

int main()
{
    try
    {
        Engine engine;
        engine.run();
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what() << '\n';
        return 1;
    }
    return 0;
}