#pragma once

#include <vector>
#include "student.hpp"

class Database{
public:
    void addStudent(const Student &s);
    void displayDatabase() const;
    bool isAdded(const Student &s);
    std::string show() const;
private:
    std::vector<Student> student_;

};