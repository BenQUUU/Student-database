#pragma once

#include <vector>
#include "student.hpp"

class Database{
public:
    void addStudent(const Student &s);
    void displayDatabase() const;
    bool isAdded(const Student &s);
    std::string show() const;
    std::string searchStudentByName(std::string name) const;
    std::string searchStudentByPESEL(std::string pesel) const;
    void sortByPESEL();
    void sortByName();
private:
    std::vector<Student> student_;
};