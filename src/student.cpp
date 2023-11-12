#include "../include/student.hpp"

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