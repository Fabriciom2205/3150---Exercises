#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("Testing LinkedList basic operations and Delete") {
    LinkedList list;
    list.insertInFront(10);
    list.insertInFront(20);
    list.insertInFront(30);
    list.deleteNode(1);

    CHECK_NOTHROW(list.traverseList());
}

TEST_CASE("Testing Copy Constructor - Deep Copy") {
    LinkedList list1;
    list1.insertInFront(5);
    list1.insertInFront(15);

    LinkedList list2 = list1;

    CHECK_NOTHROW(list2.traverseList());
}

TEST_CASE("Testing Pointer Jumping Algorithm") {
    LinkedList list;
    list.insertInFront(1);
    list.insertInFront(2);
    list.insertInFront(3);

    CHECK_NOTHROW(list.pointerJumping());
}

TEST_CASE("Testing Prefix Sum Check") {
    LinkedList list;
    list.insertInFront(1);
    list.insertInFront(2);
    list.insertInFront(3);

    CHECK(list.hasPositivePrefixSum() == true);
}