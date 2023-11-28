#include "../include/menu.hpp"

Menu::Menu(const std::string &filename) : filename_(filename) {}

void Menu::showMenu() const {
    std::cout << "#####################" << '\n';
    std::cout << "#University database#" << '\n';
    std::cout << "#####################" << '\n' << '\n';
    std::cout << "1.Add student" << '\n';
    std::cout << "2.Display database" << '\n';
    std::cout << "3.Search student by last name" << '\n';
    std::cout << "4.Search student by PESEL" << '\n';
    std::cout << "5.Sort database by PESEL" << '\n';
    std::cout << "6.Sort database by last name" << '\n';
    std::cout << "7.Remove student from database" << '\n';
    std::cout << "8.Exit" << '\n' << '\n';
    std::cout << "Your choice: ";
}

void Menu::clearScreen() const {
    #ifdef _WIN32
        std::system("cls");
    #elif defined(__unix__) || defined(__APPLE__)
        std::system("clear");
    #endif
}

void Menu::enterData() {
    std::string firstName, lastName, address, pesel, genderInput;
    Gender gender;
    int indexNumber;

    std::cout << "Student's first name: ";
    std::cin >> firstName;

    std::cout << "Student's last name: ";
    std::cin >> lastName;

    std::cout << "Student's address: ";
    std::getline(std::cin, address);
    std::getline(std::cin, address);

    std::cin.clear();
    do {
        std::cout << "Student's pesel(if the pesel will be incorrect, you will have to enter it again): ";
        std::cin >> pesel;
    }while(!Student::verifyPESEL(pesel));

    std::cout << "Student's gender(Male/Female): ";
    std::cin >> genderInput;
    gender = getGenderFromInput(genderInput);

    std::cout << "Student's index: ";
    std::cin >> indexNumber;

    db_.addStudent(Student(firstName, lastName, address, indexNumber, pesel, gender));
}

std::string Menu::getData() const {
    std::string var = "";
    std::cin >> var;

    return var;
}

void Menu::removeStudent() {
    int index{0};
    std::cout << "Enter the index of the student you want to remove: ";
    std::cin >> index;
    try {
        db_.removeStudent(index);
    }catch (std::runtime_error &e) {
        std::cout << e.what() << '\n';
    }
}

void Menu::start() {
    int choice = 0;

    try {
        JsonHandler::loadFromFile(filename_, db_);
    }catch (std::runtime_error &e) {
        std::cout << e.what() << '\n';
        return;
    }

    while(true) {
        showMenu();
        std:: cin >> choice;

        switch (choice) {
            case 1:
                enterData();
                break;
            case 2:
                db_.displayDatabase();
                break;
            case 3:
                std::cout << "Enter student's last name: ";
                std::cout << db_.searchStudentByName(getData());
                break;
            case 4:
                std::cout << "Enter student's PESEL: ";
                std::cout << db_.searchStudentByPESEL(getData());
                break;
            case 5:
                db_.sortByPESEL();
                std::cout << "The database was sorted according to PESEL" << '\n';
                break;
            case 6:
                db_.sortByName();
                std::cout << "The database was sorted according to last name" << '\n';
                break;
            case 7:
                removeStudent();
                break;
            case 8:
                JsonHandler::saveToFile(filename_, db_);
                std::cout << "The program has completed successfully" << '\n';
                return;
            default:
                std::cout << "Incorrect option, try again!" << '\n';
                break;
        }
        getchar();
        std::cout << "\nPress any button to continue..";
        getchar();
        clearScreen();
    }

}

