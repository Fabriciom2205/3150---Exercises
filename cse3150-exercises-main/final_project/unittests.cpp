#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct Node {
    string name;
    Node(string name) : name{name} {}
    shared_ptr<Node> next;
    weak_ptr<Node>   next_weak;
    ~Node() {}
};

class LinkedList {
private:
    shared_ptr<Node> root;
    weak_ptr<Node>   client_root;
    int numberOfNodes = 0;

public:
    void SERVER_buildCircularLinkedList() {
        vector<string> names = { "zero", "one", "two", "three", "four", "five" };
        numberOfNodes = names.size();

        root = make_shared<Node>(names[0]);
        shared_ptr<Node> node = root;

        for (int i = 1; i < numberOfNodes; i++) {
            node->next = make_shared<Node>(names[i]);
            node = node->next;
        }
        node->next = root;

        shared_ptr<Node> current = root;
        for (int i = 0; i < numberOfNodes; i++) {
            current->next_weak = current->next;
            current = current->next;
        }

        client_root = root;
    }

    void SERVER_deleteCircularLinkedList() {
        shared_ptr<Node> current = root->next;
        while (current && current.get() != root.get()) {
            shared_ptr<Node> next = current->next;
            current->next = nullptr;
            current = next;
        }
        if (current) current->next = nullptr;
        root = nullptr;
    }

    int  getNumberOfNodes()   const { return numberOfNodes; }
    bool clientRootIsAlive()  const { return !client_root.expired(); }
    bool serverRootIsNull()   const { return root == nullptr; }

    bool isCircular() const {
        if (!root) return false;
        shared_ptr<Node> current = root;
        for (int i = 0; i < numberOfNodes - 1; i++)
            current = current->next;
        return current->next.get() == root.get();
    }

    int countAliveWeakPtrs() const {
        shared_ptr<Node> current = client_root.lock();
        int count = 0;
        for (int i = 0; i < numberOfNodes; i++) {
            if (!current) break;
            count++;
            current = current->next_weak.lock();
        }
        return count;
    }
};

TEST_CASE("List has correct number of nodes after build") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK(ll.getNumberOfNodes() == 6);
}

TEST_CASE("List is circular after build") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK(ll.isCircular() == true);
}

TEST_CASE("All weak_ptrs are alive after build") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    CHECK(ll.countAliveWeakPtrs() == 6);
}

TEST_CASE("Server root is null after delete") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    ll.SERVER_deleteCircularLinkedList();
    CHECK(ll.serverRootIsNull() == true);
}

TEST_CASE("All weak_ptrs are expired after server deletes the list") {
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    ll.SERVER_deleteCircularLinkedList();
    CHECK(ll.clientRootIsAlive()  == false);
    CHECK(ll.countAliveWeakPtrs() == 0);
}