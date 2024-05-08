#pragma once

#include <string>
#include <vector>
#include "../include/json.hpp"
#include "../include/person.hpp"

class Student : public Person {
public:
    Student(std::string firstName,
            std::string lastName,
            std::string address,
            int indexNumber,
            std::string pesel,
            Gender gender);

    std::string show() const override;

    int getIndexNumber() const override;
    void setIndexNumber(int index) override;

    double getSalary() const override { return 0; };
    void setSalary(double salary) override{};

    json to_json() const override;
    void from_json(const json& j) override;

private:
    int indexNumber_;
};