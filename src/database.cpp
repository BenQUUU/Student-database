#include "../include/database.hpp"

void Database::addStudent(const Student& s) {
    student_.emplace_back(s);
}

bool Database::isAdded(const Student& s) {
    auto iterator = std::find(student_.begin(), student_.end(), s);

    if (iterator != student_.end()) {
        return true;
    }

    return false;
}

std::string Database::show() const {
    std::string result = "";
    for (auto&& student : student_) {
        result += student.show() + '\n';
    }

    return result;
}

void Database::displayDatabase() const {
    std::cout << show();
}

std::string Database::searchStudentByName(std::string name) const {
    for (auto&& student : student_) {
        if (student.getLastName() == name) {
            return student.show();
        }
    }
    throw std::runtime_error("No student with this name was found in the database");
}

std::string Database::searchStudentByPESEL(std::string pesel) const {
    for (auto&& student : student_) {
        if (student.getPESEL() == pesel) {
            return student.show();
        }
    }
    throw std::runtime_error("No student with this PESEL was found in the database");
}

void Database::sortByPESEL() {
    std::sort(student_.begin(), student_.end(), Student::compareByPESEL);
}

void Database::sortByName() {
    std::sort(student_.begin(), student_.end(), Student::compareByName);
}

void Database::removeStudent(int index) {
    auto it = std::remove_if(student_.begin(), student_.end(),
                             [index](const Student& student) {
                                 return student.getIndexNumber() == index;
                             });

    if (it != student_.end()) {
        student_.erase(it, student_.end());
    } else {
        throw std::runtime_error("No student with this index was found in the database");
    }
}

std::vector<Student> Database::getStudents() const {
    return student_;
}
