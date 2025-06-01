#include <iostream>
#include <string>
#include "command_utils.h"

void handleEcho(std::string &input)
{
    if (input == "echo")
    {
        std::cout << std::endl;
        return;
    }
    std::cout << input.substr(5) << std::endl;
}
