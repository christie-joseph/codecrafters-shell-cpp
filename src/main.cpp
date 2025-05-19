#include <iostream>
#include <string>

void handleEcho(std::string &input);
void handleType(std::string arg);

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true)
  {
    // Uncomment this block to pass the first stage
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    if (input == "exit 0")
    {
      return 0; // Exit the program from main
    }
    else if (input.rfind("echo", 0) == 0) // if input starts with "echo "
    {
      // Output the part after "echo "
      handleEcho(input);
    }
    else if ((input.rfind("type", 0) == 0) && input.length() > 4) // if input starts with "echo "
    {
      // Output the part after "echo "
      handleType(input.substr(5));
    }
    else
    {
      std::cout << input << ": command not found" << std::endl;
    }
  }
}

void handleEcho(std::string &input)
{
  if (input == "echo")
  {
    std::cout << std::endl;
    return;
  }
  std::cout << input.substr(5) << std::endl;
}

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
  else
  {
    std::cout << arg << ": command not found" << std::endl;
    return;
  }
}
