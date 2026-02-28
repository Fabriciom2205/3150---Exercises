#include <iostream>
#include "linked_list.h"

using namespace std;

LinkedList::LinkedList() : root{nullptr} {}

LinkedList::LinkedList(const LinkedList &other) : root{nullptr} {
    if (!other.root) return;
    root = new Node(other.root->data);
    Node* currentNew = root;
    Node* currentOld = other.root->next;
    while (currentOld && currentOld != currentOld->next) {
        currentNew->next = new Node(currentOld->data);
        currentNew = currentNew->next;
        currentOld = currentOld->next;
    }
    if (currentOld && currentOld == currentOld->next) {
        currentNew->next = new Node(currentOld->data);
        currentNew->next->next = currentNew->next;
    }
}

LinkedList::~LinkedList() {
    if (!root) return;
    Node * current = root;
    while(current && current->next != current) {
        Node * next = current->next;
        delete current;
        current = next;
    }
    if (current && current->next == current) delete current;
}

void LinkedList::insertInFront(int _data) {
    Node * insertNode = new Node(_data);

    if (root) {
         insertNode->next = root;
    } 
    root = insertNode;
}

void LinkedList::deleteNode(int i) {
    if (!root || i < 0) return;
    if (i == 0) {
        Node* temp = root;
        root = (root->next == root) ? nullptr : root->next;
        delete temp;
        return;
    }
    Node* prev = root;
    for (int count = 0; prev->next != prev && count < i - 1; ++count) prev = prev->next;
    if (prev->next && prev->next != prev) {
        Node* target = prev->next;
        prev->next = (target->next == target) ? prev : target->next;
        delete target;
    }
}

void LinkedList::pointerJumping() {
    if (!root) return;
    Node* last = root;
    while (last->next != last) last = last->next;
    
    Node* current = root;
    while (current != last) {
        current->next = last;
        current = current->next;
    }
}

bool LinkedList::hasPositivePrefixSum() {
    int sum = 0;
    Node* current = root;
    while (current) {
        sum += current->data;
        if (sum < 0) return false;
        if (current->next == current) break;
        current = current->next;
    }
    return sum >= 0;
}


void LinkedList::traverseList() { Node * current = root;

    while(current && current->next != current) {
        cout << "in ~LinkedList " 
            << static_cast<void *>(current) << " next: " 
            << static_cast<void *>(current->next) << endl;
        current = current->next;            
    }
    if (current && current->next == current) {
        cout << "in ~LinkedList " 
             << static_cast<void *>(current) << " next: " 
             << static_cast<void *>(current->next) << endl;
    }
}

ostream & operator<<(ostream & os, const LinkedList & linkelist) {
    Node * traversal = linkelist.root;
    while (traversal && traversal != traversal->next) {
        os << traversal->data << " ";
        traversal = traversal->next;
    }
    if (traversal && traversal == traversal->next) os << traversal->data;
    return os;
}