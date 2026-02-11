#include <iostream>
#include <string>
#include "student.h"

Student::Student(std::string n, int id, int numAsg) 
    : name(n), studentID(id), numAssignments(numAsg), next(nullptr) {
    if (numAsg > 0) {
        scores = new double[numAsg];
    } else {
        scores = nullptr;
    }
}

Student::~Student() {
    delete[] scores; 
}

void Student::display() const {
    std::cout << "ID: " << studentID << " | Name: " << name << " | Scores: ";
    if (numAssignments <= 0) {
        std::cout << "None";
    } else {
        for (int i = 0; i < numAssignments; i++) {
            std::cout << scores[i] << (i == numAssignments - 1 ? "" : ", ");
        }
    }
    std::cout << std::endl;
}

int main() {
    int totalStudents;
    std::cout << "How many students will be entered? ";
    std::cin >> totalStudents;

    Student* head = nullptr;

    for (int i = 0; i < totalStudents; i++) {
        std::string n;
        int id, numAsg;

        std::cout << "\nEnter Name for Student " << i + 1 << ": ";
        std::cin.ignore(); 
        std::getline(std::cin, n);
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cout << "Number of assignments: ";
        std::cin >> numAsg;

        Student* newNode = new Student(n, id, numAsg);

        for (int j = 0; j < numAsg; j++) {
            std::cout << "  Score " << j + 1 << ": ";
            std::cin >> newNode->scores[j];
        }

        newNode->next = head;
        head = newNode;
    }

    

    std::cout << "\n All Students " << std::endl;
    Student* curr = head;
    while (curr != nullptr) {
        curr->display();
        curr = curr->next;
    }

    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp; 
    }

    return 0;
}