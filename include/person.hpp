#pragma once

#include <string>
#include "gender.hpp"
#include "json.hpp"

using json = nlohmann::json;

inline Gender getGenderFromInput(const std::string& input) {
    if (input == "Male") {
        return Gender::Male;
    } else if (input == "Female") {
        return Gender::Female;
    } else {
        return Gender::Male;
    }
}

class Person {
public:
    Person();
    Person(const std::string& firstName,
           const std::string& lastName,
           const std::string& address,
           const std::string& pesel,
           Gender gender);

    virtual ~Person() = default;

    std::string getLastName() const;
    std::string getPESEL() const;
    std::string getGenderAsString() const;

    virtual std::string show() const = 0;
    virtual int getIndexNumber() const = 0;
    virtual void setIndexNumber(int index) = 0;
    virtual double getSalary() const = 0;
    virtual void setSalary(double salary) = 0;

    // bool verifyPESEL(const std::string& pesel);

    virtual json to_json() const = 0;
    virtual void from_json(const json& j) = 0;

protected:
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    std::string pesel_;
    Gender gender_;
};
