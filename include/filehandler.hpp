#pragma once

#include <fstream>
#include <iostream>
#include "../include/database.hpp"

class JsonHandler{
public:
    static void saveToFile(const std::string& filename, Database &db);
    static void loadFromFile(const std::string& filename, Database &db);
};