#include <iostream>
#include <string>
#include "command_utils.h"

void handleType(std::string arg)
{
    if (arg == "type")
    {
        std::cout << arg << " is a shell builtin" << std::endl;
        return;
    }
    else if (arg == "echo")
    {
        std::cout << arg << " is a shell builtin" << std::endl;
        return;
    }
    else if (arg == "exit")
    {
        std::cout << arg << " is a shell builtin" << std::endl;
        return;
    }
    else if (arg == "cd")
    {
        std::cout << arg << " is a shell builtin" << std::endl;
        return;
    }
    else if (arg == "pwd")
    {
        std::cout << arg << " is a shell builtin" << std::endl;
        return;
    }
    else if (isPathExec(arg))
    {
        handleTypePathExec(arg);
    }
    else
    {
        std::cout << arg << ": not found" << std::endl;
        return;
    }
}
