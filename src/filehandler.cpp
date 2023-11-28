#include "../include/filehandler.hpp"

void JsonHandler::saveToFile(const std::string& filename, Database &db) {
    json jsonData;
    for (const auto& student : db.getStudents()) {
        jsonData.push_back(student.to_json());
    }

    std::ofstream file(filename, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return;
    }
    file << std::setw(4) << jsonData << std::endl;
}

void JsonHandler::loadFromFile(const std::string& filename, Database &db) {
    std::ifstream file(filename);
    if (file.is_open()) {
        json jsonData;
        file >> jsonData;

        for (const auto& studentEntry : jsonData) {
            Student student;
            student.from_json(studentEntry);
            db.addStudent(student);
        }
    }
    else {
        std::cerr << "Something went wrong: ";
        throw std::runtime_error("Failed to open the file!");
    }
}
