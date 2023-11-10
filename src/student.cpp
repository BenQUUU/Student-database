#include "../include/student.hpp"

Student::Student(std::string firstName,
                 std::string lastName,
                 std::string address,
                 int indexNumber,
                 std::string pesel,
                 Gender gender): firstName(firstName), lastName(lastName), address(address),
                 indexNumber(indexNumber), pesel(pesel), gender(gender){}
