#include "command_utils.h"
#include <sstream>
#include <fstream>

#ifdef _WIN32
const char PATH_DELIMITER = ';';
const std::string EXE_SUFFIX = ".exe";
const char PATH_SEPARATOR = '\\';
#else
const char PATH_DELIMITER = ':';
const std::string EXE_SUFFIX = "";
const char PATH_SEPARATOR = '/';
#endif

// All parser functions in one file for easy compilation
bool isEchoCommand(const std::string &input)
{
    return input.rfind("echo", 0) == 0;
}

bool isTypeCommand(const std::string &input)
{
    return (input.rfind("type", 0) == 0) && input.length() > 4;
}

bool isExitCommand(const std::string &input)
{
    return input == "exit 0";
}

bool isPathExec(const std::string &input)
{
    const char *pathEnv = std::getenv("PATH");

    if (pathEnv == nullptr || pathEnv[0] == '\0')
    {
        return false;
    }

    std::string path(pathEnv);
    std::istringstream iss(path);
    std::string dir;

    while (std::getline(iss, dir, PATH_DELIMITER))
    {
        if (dir.empty())
            continue;

        // Build full path to the executable
        std::string fullPath = dir + PATH_SEPARATOR + input;
        std::ifstream f1(fullPath);
        if (f1.good())
            return true;

        // On Windows, also try with ".exe"
        if (!EXE_SUFFIX.empty())
        {
            std::string fullPathExe = fullPath + EXE_SUFFIX;
            std::ifstream f2(fullPathExe);
            if (f2.good())
                return true;
        }
    }

    return false;
}

CommandType parseCommandType(const std::string &input)
{
    if (isEchoCommand(input))
    {
        return CommandType::ECHO;
    }
    else if (isTypeCommand(input))
    {
        return CommandType::TYPE;
    }
    else if (isExitCommand(input))
    {
        return CommandType::EXIT;
    }
    return CommandType::UNKNOWN;
}

std::vector<std::string> parseArguments(const std::string &input)
{
    std::vector<std::string> args;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        args.push_back(token);
    }

    return args;
}

std::string getCommandName(const std::string &input)
{
    std::istringstream iss(input);
    std::string command;
    iss >> command;
    return command;
}
