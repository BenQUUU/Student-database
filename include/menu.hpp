#pragma once

#ifdef _WIN32
#include <cstdlib>
#elif defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

#include "../include/database.hpp"
#include "../include/filehandler.hpp"
#include "../include/student.hpp"

class Menu {
public:
    Menu(const std::string &filename);
    void start();
private:
    Database db_;
    std::string filename_;
    void showMenu() const;
    void clearScreen() const;
    void enterData();
    std::string getData() const;
    void removeStudent();
};