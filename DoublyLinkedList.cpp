#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() {      //definicja konstruktora pustej listy
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {         //definicja destruktora listy
    Node* current = head;                       //tworzymy wskaźnik "current" na pierwszy (head) element listy
    while(current != nullptr){                  //dopóki są elementy (dopóki wskaźnik na następny element nie jest nullptr)
        Node* nextNode = current->next;         //tworzymy destruktor nextNode, który bierze wartość next z currenta do zapamiętania
        delete current;                         //usuwamy current
        current = nextNode;                     //nasz nowy current jest wskaźnikiem nowego na nowy head (wcześniej drugi node)
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::pushFront(int value) {   
    Node* newNode = new Node(value);            //tworzymy wskaźnik na nowy node, konstruktor ustawia go na value(val), next i prev nullptr
                                                //"new" zwraca ADRES utworzonego elementu, dlatego możemy go przypisać go do wskaźnika
    if(head == nullptr) {                       //jeśli jest to pierwszy element listy
        head = tail = newNode;                  //head i tail ustawiamy na newNode
    }
    else {
        newNode->next = head;                   //jeśli nie, to next nowego ustawiamy na head obecny
        head->prev = newNode;                   //prev heada obecnego ustawiamy na newNode
        head = newNode;                         //ustawiamy nowy head na newNo'dzie
    }
    size++;
}

void DoublyLinkedList::pushBack(int value) {
    Node* newNode = new Node(value);            //nie wiem czy ktoś będzie czytał ten sam komentach XYZ raz, więc po prostu [pozdrawiam :P]

    if(head == nullptr) {                       //ponownie sprawdzenie czy lista jest pusta
        head = tail = newNode;
    }
    else {                                      //jeśli nie
        tail->next = newNode;                   //next taila staje sie newNode'm
        newNode->prev = tail;                   //prev newNode'a ustawiam na tail (obecny)
        tail = newNode;                         //zmieniam tail na newNode
    }
    size++;
}

void DoublyLinkedList::pushAt(int index, int value) {
    if(index < 0 || index > size) {             //te 3 ify to dosłowna kopia z SinglyLinkedList
        return;                                 //przypadek indexu poza zakresem
    }

    if(index == 0) {                            //jeśli index == 0 to dodajemy jako pierwszy element...
        pushFront(value);                       //... czyli używamy push fronta xpp
        return;                                 
    }

    if(index == size) {                         //a jeśli index == size to dodajemy na koniec...
        pushBack(value);                        //... czyli używamy push backa xpppp
        return;
    }                                           

    Node* newNode = new Node(value);
    Node* current = head;
    for(int i = 0; i < index - 1; i++) {        //ponownie ten sam mechanizm iteracyjny
        current = current->next;
    }

    newNode->next = current->next;              //next newNode zostaje ustawiony na next currenta
    newNode->prev = current;                    //prev newNode zostaje ustawiony na currenta (bo newNode bedzie przed nim)
    current->next->prev = newNode;              //to jest śmieszne, bo z pozycji currenta, ustawiamy prev jego nexta na newNode
                                                //(wpychamy newNode pomiędzy current i jego next)
    current->next = newNode;                    //ustawiamy newNode jako next currenta
    
    size++;
}

void DoublyLinkedList::popFront() {
    if(head == nullptr){                        //jeśli lista jest pusta => return
        return;
    }

    Node* oldHead = head;                       //tworzymy oldHead do przechowania head (by go usunąć)
    head = head->next;                          //nowy head jest nextem obecnego (jeszcze) head'a

    delete oldHead;                             //usuwamy stary head
    size--;                                     //zmniejszenie rozmiar zliczany

    if(head == nullptr) {                       //jeśli usuneliśmy ostatni element
        tail = nullptr;                         //tail ustawiamy na nullptr
    }
    else {
        head->prev = nullptr;
    }
}

void DoublyLinkedList::popBack() {
    if(head == nullptr) {                       //jeśli lista jest pusta => return
        return;
    }

    Node* oldTail = tail;                       //jak z oldHead, robie oldTail
    tail = tail->prev;                          //nowy tail ustawiam prev starego taila

    delete oldTail;                             //usuwam oldTail
    size--;                                     //zmniejszam rozmiar zliczany

    if(tail == nullptr) {                       //tu sprawdzamy czy lista miała tylko jeden element, jeśli tak, to tail ustawił się na nullptr
        head = nullptr;                         //wtedy ustawiam też head na nullptr
    }
    else {
        tail->next = nullptr;                   //jeśli nie był to jedyny element, to next taila ustawiam na nullptr
    }
}