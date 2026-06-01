#pragma once

#include <iostream>
#include <string>

namespace ilog
{
    constexpr const char* RESET = "\033[0m";
    constexpr const char* WHITE = "\033[37m";
    constexpr const char* BLUE = "\033[34m";
    constexpr const char* GREEN = "\033[32m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* RED = "\033[31m";
    constexpr const char* RED_BOLD = "\033[1;91m";

    inline void info(const std::string &msg) { std::cout << WHITE << "[INFO] " << msg << RESET << "\n"; }
    inline void debug(const std::string &msg) { std::cout << BLUE << "[DEBUG] " << msg << RESET << "\n"; }
    inline void warn(const std::string &msg) { std::cout << YELLOW << "[WARN] " << msg << RESET << "\n"; }
    inline void success(const std::string &msg) { std::cout << GREEN << "[SUCCESS] " << msg << RESET << "\n"; }
    inline void error(const std::string &msg) { std::cerr << RED << "[ERROR] " << msg << RESET << "\n"; }
    inline void fatal(const std::string &msg) { std::cerr << RED_BOLD << "[FATAL] " << msg << RESET << "\n"; }
}
