#include <iostream>
#include "../include/menu.hpp"

int main() {
    std::string filename = "";
    std::cout << "Enter the name of the file to write/read: ";
    std::cin >> filename;
    Menu menu(filename);
    menu.clearScreen();
    menu.start();
    return 0;
}
