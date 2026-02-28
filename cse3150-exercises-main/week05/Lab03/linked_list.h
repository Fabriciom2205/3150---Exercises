#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
    friend ostream & operator<<(ostream & os, const LinkedList & linkelist);
    Node * root;

    public:
        LinkedList();
        LinkedList(const LinkedList &other);
        ~LinkedList();
        
        void insertInFront(int _data);
        void traverseList();
        void deleteNode(int i);
        bool hasPositivePrefixSum();
        void pointerJumping();
};

#endif