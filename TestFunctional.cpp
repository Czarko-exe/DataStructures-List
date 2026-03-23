#include <iostream>
#include "DynamicArray.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

// void testDynamicArray();

void testSinglyLinkedList() {
    SinglyLinkedList list;

    cout << "\npushBack 1,2,4\n";
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(4);
    list.print();

    cout << "pushFront 0\n";
    list.pushFront(0);
    list.print();

    cout << "pushAt(3, 3)\n";
    list.pushAt(3,3);
    list.print();

    cout << "popFront()\n";
    list.popFront();
    list.print();

    cout << "popBack()\n";
    list.popBack();
    list.print();

    cout << "popAt(2)\n";
    list.popAt(2);
    list.print();

    cout << "find(2) = " << list.find(2) << endl;

    cout << "clear()\n";
    list.clear();
    list.print();
};

 void testDoublyLinkedList() {
    DoublyLinkedList list;

    cout << "\npushBack 1,2,4\n";
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(4);
    list.print();

    cout << "pushFront 0\n";
    list.pushFront(0);
    list.print();

    cout << "pushAt(3, 3)\n";
    list.pushAt(3,3);
    list.print();

    cout << "popFront()\n";
    list.popFront();
    list.print();

    cout << "popBack()\n";
    list.popBack();
    list.print();

    cout << "popAt(2)\n";
    list.popAt(2);
    list.print();

    cout << "find(2) = " << list.find(2) << endl;

    cout << "clear()\n";
    list.clear();
    list.print();
 };

int main() {
    // cout << "-----TEST TABLICY DYNAMICZNEJ-----";
    // testDynamicArray();

    cout << "-----TEST LISTY JEDNOKIERUNKOWEJ-----";
    testSinglyLinkedList();

    cout << "-----TEST LISTY DWUKIERUNKOWEJ-----";
    testDoublyLinkedList();

    return 0;
}