cmake_minimum_required(VERSION 3.14)
project(student_database)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
        src/student.cpp
        src/database.cpp
        src/filehandler.cpp
        src/menu.cpp
        src/person.cpp)
set(FLAGS -Wall -Wextra -Wpedantic -Werror -std=c++20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} ${SOURCE} src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

enable_testing()
add_executable(${PROJECT_NAME}-ut tests/tests.cpp ${SOURCE})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

target_link_libraries(
        ${PROJECT_NAME}-ut
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

