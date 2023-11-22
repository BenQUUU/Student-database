#include <iostream>
#include "../include/menu.hpp"

int main() {
    Menu menu("../students.json");
    menu.start();
    return 0;
}
