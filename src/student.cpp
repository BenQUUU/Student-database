#include "../include/student.hpp"

Student::Student(std::string firstName,
                 std::string lastName,
                 std::string address,
                 int indexNumber,
                 std::string pesel,
                 Gender gender)
    : Person(firstName, lastName, address, pesel, gender) {
    indexNumber_ = indexNumber;
}

std::string Student::show() const {
    return firstName_ + " " + lastName_ + "; " + address_ + "; " + std::to_string(indexNumber_) + "; " + pesel_ + "; " + getGenderAsString();
}

int Student::getIndexNumber() const {
    return indexNumber_;
}

json Student::to_json() const {
    return {
        {"firstName", firstName_},
        {"lastName", lastName_},
        {"address", address_},
        {"indexNumber", indexNumber_},
        {"pesel", pesel_},
        {"gender", getGenderAsString()}};
}

void Student::from_json(const json& j) {
    firstName_ = j.at("firstName").get<std::string>();
    lastName_ = j.at("lastName").get<std::string>();
    address_ = j.at("address").get<std::string>();
    indexNumber_ = j.at("indexNumber").get<int>();
    pesel_ = j.at("pesel").get<std::string>();

    std::string genderStr = j.at("gender").get<std::string>();
    if (genderStr == "Male") {
        gender_ = Gender::Male;
    } else if (genderStr == "Female") {
        gender_ = Gender::Female;
    } else {
        gender_ = Gender::Male;
    }
}