#include <iostream>
#include <string>
#include "command_utils.h"

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true)
  {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    
    if (input == "exit 0")
    {
      return 0; // Exit the program from main
    }
    else if (isEchoCommand(input))
    {
      handleEcho(input);
    }
    else if (isTypeCommand(input))
    {
      handleType(input.substr(5));
    }
    else
    {
      std::cout << input << ": command not found" << std::endl;
    }
  }
}
