#include <string>

struct Student {
    std::string name;
    int studentID;
    int numAssignments;
    double* scores;
    Student* next;

    Student(std::string n, int id, int numAsg);
    ~Student(); 
};