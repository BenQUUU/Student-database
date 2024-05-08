#include "../include/person.hpp"


Person::Person(const std::string& firstName,
               const std::string& lastName,
               const std::string& address,
               const std::string& pesel,
               Gender gender)
    : firstName_(firstName),
      lastName_(lastName),
      address_(address),
      pesel_(pesel),
      gender_(gender) {
}

std::string Person::getLastName() const {
    return lastName_;
}

std::string Person::getPESEL() const {
    return pesel_;
}

std::string Person::getGenderAsString() const {
    switch (gender_) {
    case Gender::Male:
        return "Male";
    case Gender::Female:
        return "Female";
    }

    return "Unknown";
}

// bool Person::verifyPESEL(const std::string& pesel) {
//     const std::vector digitWeight{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
//     int result = 0;
//     int checkDigit = 0;
//
//     if (pesel.length() != 11) {
//         return false;
//     }
//
//     for (size_t i = 0; i < digitWeight.size(); i++) {
//         result += digitWeight.at(i) * (pesel[i] - '0');
//     }
//
//     checkDigit = (10 - (result % 10)) % 10;
//
//     return checkDigit == pesel[10] - '0';
// }