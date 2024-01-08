#include <gtest/gtest.h>
#include "../include/database.hpp"
#include "../include/student.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
};

TEST_F(DatabaseTest, CanAddStudentToDb) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male};

    EXPECT_FALSE(db.isAdded(adam));
    db.addStudent(adam);
    EXPECT_TRUE(db.isAdded(adam));
}

TEST_F(DatabaseTest, DisplayEmptyDb) {
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNotEmptyDb) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male};
    db.addStudent(adam);

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344556; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SearchStudentByName) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male};
    db.addStudent(adam);

    auto content = db.searchStudentByName("Kowalski");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344556; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SearchStudentByNameThrowsException) {
    std::string notExistingName = "Something";

    ASSERT_THROW({ db.searchStudentByName(notExistingName); }, std::runtime_error);
}

TEST_F(DatabaseTest, SearchStudentByPESEL) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male};
    db.addStudent(adam);

    auto content = db.searchStudentByPESEL("11223344556");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344556; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SearchStudentByPESELThrowsException) {
    std::string notExistingPESEL = "11111111111";

    ASSERT_THROW({ db.searchStudentByName(notExistingPESEL); }, std::runtime_error);
}

TEST_F(DatabaseTest, SortDbByPESEL) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "51223344556",
        Gender::Male};
    db.addStudent(adam);

    Student anna{
        "Anna",
        "Jowalska",
        "ul. Dobra 139, 00-200 Warszawa",
        234551,
        "31223344556",
        Gender::Female};
    db.addStudent(anna);

    db.sortByPESEL();
    auto content = db.show();
    auto expected = "Anna Jowalska; ul. Dobra 139, 00-200 Warszawa; 234551; 31223344556; FemaleAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 51223344556; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SortDbByName) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "51223344556",
        Gender::Male};
    db.addStudent(adam);

    Student anna{
        "Anna",
        "Jowalska",
        "ul. Dobra 139, 00-200 Warszawa",
        234551,
        "31223344556",
        Gender::Female};
    db.addStudent(anna);

    db.sortByName();
    auto content = db.show();
    auto expected = "Anna Jowalska; ul. Dobra 139, 00-200 Warszawa; 234551; 31223344556; FemaleAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 51223344556; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, RemoveStudentFromDB) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "51223344556",
        Gender::Male};
    db.addStudent(adam);

    db.removeStudent(123456);

    auto content = db.show();
    auto expected = "";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, PESELIsCorrect) {
    EXPECT_TRUE(Student::verifyPESEL("90090515836"));
}

TEST_F(DatabaseTest, PESELIsIncorrect) {
    EXPECT_FALSE(Student::verifyPESEL("11282512230"));
    EXPECT_FALSE(Student::verifyPESEL("1128"));
}
