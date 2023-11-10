#pragma once

#include <string>

enum class Gender{
    male,
    female
};

class Student{
public:
    Student(std::string firstName,
    std::string lastName,
    std::string address,
    int indexNumber,
    std::string pesel,
    Gender gender);
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    int indexNumber;
    std::string pesel;
    Gender gender;
};