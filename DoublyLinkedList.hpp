#pragma once                //żeby nam nie definiowało dwa razy tego samego
#include <iostream>

struct DNode {              //struct to po prostu publiczny class
    int value;
    DNode* next;
    DNode* prev;            //wskaźniki na next JAK i prev (następny i poprzedni node)

    DNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:                    //identycznie jak w liście jednokierunkowej
    DNode* head;
    DNode* tail;
    int size;
public:
    DoublyLinkedList();     //tak samo deklarujemy konstruktor i destruktor
    ~DoublyLinkedList();

    void pushFront(int value);      //te same deklaracje metod ale będą inne definicje w .cpp
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