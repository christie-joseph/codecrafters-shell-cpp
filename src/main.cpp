#include <iostream>
#include <string>

void handleEcho(std::string &input);

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
