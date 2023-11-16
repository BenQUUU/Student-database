#pragma once

#include <string>
#include <vector>
#include "../include/json.hpp"

using json = nlohmann::json;

enum class Gender{
    Male,
    Female
};

class Student{
public:
    Student() = default;
    Student(std::string firstName,
    std::string lastName,
    std::string address,
    int indexNumber,
    std::string pesel,
    Gender gender);
    bool operator==(const Student &other) const;
    std::string show() const;
    std::string getLastName() const;
    std::string getPESEL() const;
    int getIndexNumber() const;
    static bool compareByPESEL(const Student &a, const Student &b);
    static bool compareByName(const Student &a, const Student &b);
    static bool verifyPESEL(const std::string &pesel);
    json to_json() const;
    void from_json(const json &j);
private:
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    int indexNumber_;
    std::string pesel_;
    Gender gender_;
    std::string getGenderAsString() const;
};