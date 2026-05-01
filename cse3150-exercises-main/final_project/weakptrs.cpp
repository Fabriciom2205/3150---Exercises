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

    ~Node() { cout << "Node [" << name << "] destructor" << endl; }
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

    //Step 2
    void SERVER_printLinkedList() {
        cout << "\nServer (step 2):" << endl;

        shared_ptr<Node> current = root;
        for (int i = 0; i < numberOfNodes; i++) {
            cout << "[" << current->name << "]"
                 << " : use_count: " << current.use_count()
                 << " address: "     << current.get()
                 << " next (from shared_ptr): " << current->next.get()
                 << endl;
            current = current->next;
        }
    }

    //Step 3
    void CLIENT_printLinkedList() {
        cout << "\nClient (step 3):" << endl;

        shared_ptr<Node> current = client_root.lock();

        for (int i = 0; i < numberOfNodes; i++) {
            if (current) {
                shared_ptr<Node> next_node = current->next_weak.lock();

                cout << "[" << current->name << "]"
                     << " : use_count: " << current.use_count()
                     << " address: "     << current.get()
                     << " next (from weak_ptr): "
                     << (next_node ? next_node.get() : nullptr)
                     << endl;

                current = next_node;
            } else {
                cout << "Yipes! shared_ptr not available" << endl;
            }
        }
    }

    //Step 4
    void SERVER_deleteCircularLinkedList() {
        cout << "\nServer is deleting the shared_ptrs (step 4):" << endl;

        shared_ptr<Node> current = root->next;
        while (current && current.get() != root.get()) {
            shared_ptr<Node> next = current->next;
            current->next = nullptr;
            current = next;
        }

        if (current) {
            current->next = nullptr;
        }

        root = nullptr;
    }

    //Step 5
    void CLIENT_printLinkedList_afterDelete() {
        cout << "\nClient after linked list deleted (step 5):" << endl;

        shared_ptr<Node> current = client_root.lock();

        for (int i = 0; i < numberOfNodes; i++) {
            if (current) {
                shared_ptr<Node> next_node = current->next_weak.lock();

                cout << "[" << current->name << "]"
                     << " : use_count: " << current.use_count()
                     << " address: "     << current.get()
                     << " next (from weak_ptr): "
                     << (next_node ? next_node.get() : nullptr)
                     << endl;

                current = next_node;
            } else {
                cout << "Yipes! shared_ptr not available" << endl;
            }
        }
    }

    int getNumberOfNodes()   const { return numberOfNodes; }
    bool clientRootIsAlive() const { return !client_root.expired(); }
    bool serverRootIsNull()  const { return root == nullptr; }

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

int main() {
    LinkedList ll;

    // Step 1
    ll.SERVER_buildCircularLinkedList();

    // Step 2
    ll.SERVER_printLinkedList();

    // Step 3
    ll.CLIENT_printLinkedList();

    // Step 4
    ll.SERVER_deleteCircularLinkedList();

    // Step 5
    ll.CLIENT_printLinkedList_afterDelete();

    return 0;
}