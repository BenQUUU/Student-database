#include <algorithm>
#include <iostream>
#include "../include/database.hpp"


void Database::addStudent(const Student &s) {
    student_.emplace_back(s);
}

bool Database::isAdded(const Student &s) {
    auto iterator = std::find(student_.begin(), student_.end(), s);

    if(iterator != student_.end()){
        return true;
    }

    return false;
}

std::string Database::show() const {
    std::string result = "";
    for(auto && student: student_){
        result += student.show();
    }

    return result;
}

void Database::displayDatabase() const {
    std::cout << show();
}

std::string Database::searchStudentByName(std::string name) const {
    for(auto && student : student_){
        if(student.getLastName() == name){
            return student.show();
        }
    }
    throw std::runtime_error("No student with this name was found in the database");
}

std::string Database::searchStudentByPESEL(std::string pesel) const {
    for(auto && student : student_){
        if(student.getPESEL() == pesel){
            return student.show();
        }
    }
    throw std::runtime_error("No student with this PESEL was found in the database");
}


