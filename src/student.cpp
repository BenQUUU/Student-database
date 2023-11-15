#include "../include/student.hpp"
#include <vector>

Student::Student(std::string firstName,
                 std::string lastName,
                 std::string address,
                 int indexNumber,
                 std::string pesel,
                 Gender gender):
            firstName_(firstName)
          , lastName_(lastName)
          , address_(address)
          , indexNumber_(indexNumber)
          , pesel_(pesel)
          , gender_(gender)
{}

bool Student::operator==(const Student &other) const{
    return (firstName_ == other.firstName_) &&
            (lastName_ == other.lastName_) &&
            (address_ == other.address_) &&
            (indexNumber_ == other.indexNumber_) &&
            (pesel_ == other.pesel_) &&
            (gender_ == other.gender_);
}

std::string Student::getGenderAsString() const {
    switch (gender_) {
        case Gender::Male:
            return "Male";
        case Gender::Female:
            return "Female";
    }
}

std::string Student::show() const {
    return firstName_ + " "
        + lastName_ + "; "
        + address_ + "; "
        + std::to_string(indexNumber_) + "; "
        + pesel_ + "; "
        + getGenderAsString();
}

std::string Student::getLastName() const {
    return lastName_;
}

std::string Student::getPESEL() const {
    return pesel_;
}

bool Student::compareByPESEL(const Student &a, const Student &b) {
    return a.pesel_ < b.pesel_;
}

bool Student::compareByName(const Student &a, const Student &b) {
    return a.lastName_ < b.lastName_;
}

int Student::getIndexNumber() const {
    return indexNumber_;
}

bool Student::verifyPESEL(const std::string &pesel){
    const std::vector<int> digitWeight{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int result = 0;
    int checkDigit = 0;

    if(pesel.length() != 11) {
        return false;
    }

    for(size_t i = 0; i < digitWeight.size(); i++) {
        result += digitWeight.at(i) * (pesel[i] - '0');
    }

    checkDigit = (10 -(result % 10)) % 10;

    return checkDigit == pesel[10] - '0';
}