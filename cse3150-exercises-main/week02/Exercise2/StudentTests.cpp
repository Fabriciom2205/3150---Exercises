#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Creating a student with constructor") {
    Student student("Fabricio", 90, 3);
    
    CHECK(student.getName() == "Fabricio");
    CHECK(student.final == 90);
    CHECK(student.number_of_homeworks == 3);
    CHECK(student.hw_grades != nullptr);
}

TEST_CASE("Copy constructor makes independent copy") {
    Student original("Billy", 85, 2);
    original.hw_grades[0] = 95;
    original.hw_grades[1] = 88;
    
    Student copy(original);
    
    original.hw_grades[0] = 50;
    
    CHECK(copy.hw_grades[0] == 95);
    CHECK(copy.hw_grades[1] == 88);
    CHECK(original.hw_grades[0] == 50);
}

TEST_CASE("Student with zero homeworks") {
    Student student("Fabricio", 75, 0);
    
    CHECK(student.getName() == "Fabricio");
    CHECK(student.final == 75);
    CHECK(student.number_of_homeworks == 0);
}

TEST_CASE("Setting and getting homework grades") {
    Student student("Fabricio", 88, 3);
    
    student.hw_grades[0] = 85;
    student.hw_grades[1] = 90;
    student.hw_grades[2] = 92;
    
    CHECK(student.hw_grades[0] == 85);
    CHECK(student.hw_grades[1] == 90);
    CHECK(student.hw_grades[2] == 92);
}

TEST_CASE("getName and setName methods") {
    Student student("Fabricio", 95, 1);
    
    CHECK(student.getName() == "Fabricio");
    
    student.setName("Billy");
    CHECK(student.getName() == "Billy");
}