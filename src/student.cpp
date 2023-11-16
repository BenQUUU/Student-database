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

    return "Unknown";
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

json Student::to_json() const {
    return {
                {"firstName", firstName_},
                {"lastName", lastName_},
                {"address", address_},
                {"indexNumber", indexNumber_},
                {"pesel", pesel_},
                {"gender", getGenderAsString()}
    };
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