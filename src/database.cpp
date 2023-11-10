#include <algorithm>
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
