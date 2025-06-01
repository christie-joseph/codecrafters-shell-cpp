#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "command_utils.h"

#ifdef _WIN32
const char PATH_DELIMITER = ';';
const std::string EXE_SUFFIX = ".exe";
const char PATH_SEPARATOR = '\\';
#else
const char PATH_DELIMITER = ':';
const std::string EXE_SUFFIX = "";
const char PATH_SEPARATOR = '/';
#endif

void handleTypePathExec(std::string arg)
{
    {
        const char *pathEnv = std::getenv("PATH");

        std::string path(pathEnv);
        std::istringstream iss(path);
        std::string dir;

        while (std::getline(iss, dir, PATH_DELIMITER))
        {
            if (dir.empty())
                continue;

            // Build full path to the executable
            std::string fullPath = dir + PATH_SEPARATOR + arg;
            std::ifstream f1(fullPath);
            if (f1.good())
                std::cout << arg << " is " << fullPath << std::endl;

            // On Windows, also try with ".exe"
            if (!EXE_SUFFIX.empty())
            {
                std::string fullPathExe = fullPath + EXE_SUFFIX;
                std::ifstream f2(fullPathExe);
                if (f2.good())
                    std::cout << arg << " is " << fullPath << std::endl;
            }
        }
    }
}
