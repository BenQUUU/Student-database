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


