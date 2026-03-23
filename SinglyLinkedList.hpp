#pragma once            //żeby nam nie definiowało dwa razy tego samego
#include <iostream>


struct SNode {           //struct to po prostu publiczny class
    int value;
    SNode* next;         //wskaźnik na next element 

    SNode(int val) : value(val), next(nullptr) {}        //konstruktor
};

class SinglyLinkedList {
private:
    SNode* head;         //wskaźnik na head
    SNode* tail;         //wskaźnik na tail
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void pushFront(int value);      //tu deklaruje operacje jakie zdefiniuje w cpp
    void pushBack(int value);
    void pushAt(int index, int value);

    void popFront();
    void popBack();
    void popAt(int index);

    int find(int value) const;      //const żeby tylko czytać i móc pracować na obiektach const

    int getSize() const {return size;}          //od razu return bo to krótka implementacja
    bool isEmpty() const {return size==0;}

//-------------------------DODATKOWE FUNKCJONALNOŚCI DLA TESTÓW I CZYTELNOŚCI ;PP------------------------------------------------

    void print() const;
    void clear();
};