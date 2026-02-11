#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Testing Student Struct - Basic Construction") {
    Student s("Fabricio", 101, 3);
    
    CHECK(s.name == "Fabricio");
    CHECK(s.studentID == 101);
    CHECK(s.numAssignments == 3);
    CHECK(s.scores != nullptr);
    CHECK(s.next == nullptr);
}

TEST_CASE("Testing Linked List Connectivity") {
    Student* head = new Student("Fabricio", 101, 2);
    Student* second = new Student("Bob", 102, 1);

    head->next = second;

    SUBCASE("Linking check") {
        CHECK(head->next == second);
        CHECK(head->next->name == "Bob");
        CHECK(second->next == nullptr);
    }

    delete head;
    delete second;
}

TEST_CASE("Zero Assignments") {
    Student s("John", 999, 0);
    
    CHECK(s.numAssignments == 0);
}

TEST_CASE("Data Integrity in Scores Array") {
    Student* s = new Student("Charlie", 103, 2);
    
    s->scores[0] = 95.5;
    s->scores[1] = 88.0;

    CHECK(s->scores[0] == 95.5);
    CHECK(s->scores[1] == 88.0);

    delete s;
}