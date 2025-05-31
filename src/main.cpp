#include <iostream>
#include <string>
#include <vector>
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

    CommandType cmdType = parseCommandType(input);

    switch (cmdType)
    {
    case CommandType::EXIT:
      return 0;
    case CommandType::ECHO:
      handleEcho(input);
      break;
    case CommandType::TYPE:
    {
      std::vector<std::string> args = parseArguments(input);
      if (args.size() > 1)
      {
        handleType(args[1]);
      }
    }
    break;
    case CommandType::UNKNOWN:
    default:
    {
      std::string cmdName = getCommandName(input);
      if (!cmdName.empty())
      {
        std::cout << cmdName << ": command not found" << std::endl;
      }
    }
    break;
    }
  }
}
