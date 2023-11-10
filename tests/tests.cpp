#include <gtest/gtest.h>
#include "../include/student.hpp"
#include "../include/database.hpp"

TEST(CheckStructure, CanAddStudentToDb){
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male
    };

    Database db;
    db.addStudent(adam);
    EXPECT_TRUE(db.isAdded(adam));
}



