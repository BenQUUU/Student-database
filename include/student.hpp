#pragma once

#include <string>

enum class Gender{
    Male,
    Female
};

class Student{
public:
    Student(std::string firstName,
    std::string lastName,
    std::string address,
    int indexNumber,
    std::string pesel,
    Gender gender);
    bool operator==(const Student &other) const;
    std::string show() const;
    std::string getLastName() const;
private:
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    int indexNumber_;
    std::string pesel_;
    Gender gender_;
    std::string getGenderAsString() const;
};