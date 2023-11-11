#include <gtest/gtest.h>
#include "../include/student.hpp"
#include "../include/database.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
};

TEST_F(DatabaseTest, CanAddStudentToDb){
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male
    };

    EXPECT_FALSE(db.isAdded(adam));
    db.addStudent(adam);
    EXPECT_TRUE(db.isAdded(adam));
}

TEST_F(DatabaseTest, DisplayEmptyDb){
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNotEmptyDb){
    Student adam{
            "Adam",
            "Kowalski",
            "ul. Dobra 134, 00-200 Warszawa",
            123456,
            "11223344556",
            Gender::Male
    };
    db.addStudent(adam);

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344556; Male";
    EXPECT_EQ(content, expected);
}

