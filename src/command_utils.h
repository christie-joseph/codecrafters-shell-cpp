#ifndef COMMAND_UTILS_H
#define COMMAND_UTILS_H

#include <string>
#include <vector>

// Command types
enum class CommandType
{
    ECHO,
    TYPE,
    EXIT,
    UNKNOWN
};

// Parser utility functions
bool isEchoCommand(const std::string &input);
bool isTypeCommand(const std::string &input);
bool isExitCommand(const std::string &input);
bool isPathExec(const std::string &input);

// New parser functions
CommandType parseCommandType(const std::string &input);
std::vector<std::string> parseArguments(const std::string &input);
std::string getCommandName(const std::string &input);

// Handler function declarations (implemented in separate files)
void handleEcho(std::string &input);
void handleType(std::string arg);
void handleTypePathExec(std::string arg);

#endif
