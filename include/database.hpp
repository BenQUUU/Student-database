#pragma once

#include <vector>
#include "student.hpp"

class Database{
public:
    void addStudent(const Student &s);
    bool isAdded(const Student &s);
private:
    std::vector<Student> student_;
};