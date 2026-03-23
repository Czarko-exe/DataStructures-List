#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() {      //definicja konstruktora pustej listy
    head = nullptr;
    tail = nullptr;
    size = 0;
}

SinglyLinkedList::~SinglyLinkedList() {         //definicja destruktora listy
    SNode* current = head;                      //tworzymy wskaźnik "current" na pierwszy (head) element listy
    while(current != nullptr){                  //dopóki są elementy (dopóki wskaźnik na następny element nie jest nullptr)
        SNode* nextNode = current->next;        //tworzymy destruktor nextNode, który bierze wartość next z currenta do zapamiętania
        delete current;                         //usuwamy current
        current = nextNode;                     //nasz nowy current jest wskaźnikiem nowego na nowy head (wcześniej drugi node)
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void SinglyLinkedList::pushFront(int value) {
    SNode* newNode = new SNode(value);          //tworzymy wskaźnik na nowy node, konstruktor ustawia go na value(val) i next = nullptr
                                                //"new" zwraca ADRES utworzonego elementu, dlatego możemy go przypisać go do wskaźnika
    if(head == nullptr) {                       
        head = tail = newNode;                  //jeśli head == nullptr, oznacza to że jest to pierwszy element listy                       
    }                                           //ustawiamy wtedy zarówno head jak i tail na newNode
    else {
        newNode->next = head;                   //next newNode'a wskazuje na obecny head, więc "podłączamy" go do listy
        head = newNode;                         //ustawiamy head na newNode
    }
    size++;                                     //zwiekszamy zmienną size reprezentującą ilość elementów w tablicy, NIE JEJ ROZMIAR
}

void SinglyLinkedList::pushBack(int value) {
    SNode* newNode = new SNode(value);          //ponownie tworzymy nowy element

    if(head == nullptr) {                       //sprawdzamy czy to nie pierwszy element listy (jeśli head == nullptr => tak)
        head = tail = newNode;                  //ustawiamy wtedy zarówno head jak i tail na newNode
    }
    else {                                      //jeśli NIE (jest już coś w liście)
        tail->next = newNode;                   //wskaźnik next taila zmieniamy z nullptr na newNode
        tail = newNode;                         //ustawiamy newNode jako wksaźnik tail
    }
    size++;
}

void SinglyLinkedList::pushAt(int index, int value) {
    if(index < 0 || index > size) {
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

    SNode* newNode = new SNode(value);          //znane nam już tworzenie nowego node'a

    SNode* current = head;                      //tworzymy wskaźnik current z adresem z head
    for(int i = 0; i < index - 1; i++) {        //iterujemy aż dostaniemy sie do elementu PRZED (index - 1) pozycją której oczekujemy
        current = current->next;                //ustawiamy tymczasowe currenty aż dotrzemy do oczekiwanego
    }
    newNode->next = current->next;              //next newNode'a dajemy jako next currenta (wchodzimy między current a next)
    current->next = newNode;                    //i ustawiamy next currenta na newNode

    size++;
}

void SinglyLinkedList::popFront() {
    if(head == nullptr) {                       //przypadek jeśli lista jest pusta
        return;
    }

    SNode* oldHead = head;                      //tworzymy wskaźnik oldHead który przechowa nam head
    head = head->next;                          //zmieniamy head, na wcześniej drugi element listy

    delete oldHead;                             //usuwamy wskaźnik pomocniczy (stary head)
    size--;                                     //zmniejszenie licznika elementów

    if(head == nullptr) {                       //jeśli przez usunięcie elementu lista stała się pusta, ustawiamy tail na nullptr
        tail = nullptr;
    }
}

void SinglyLinkedList::popBack() {
    if(head == nullptr) {                       //przypadek jeśli lista jest pusta (znowu)
        return;
    }

    if(head == tail) {                          //przypadek jeśli lista ma tylko jeden element (head i tail wskazują na ten sam node)
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }

    SNode* current = head;                      //(znowu) będziemy iterować przez X (prawie wszystkie) elementów listy
    while(current->next != tail) {              //dopóki next currenta nie jest nullptr'em
        current = current->next;                //przechodzimy przez wszystkie elementy aż do przedostatniego
    }

    delete tail;                                //usuwamy obecny tail
    tail = current;                             //ustawiamy nowy wskaźnik tail na current (poprzednio przedostatni)
    tail->next = nullptr;                       //ustawiamy next currenta (nowego taila) na nullptr
    size--;                                     //zmniejszamy size
}

void SinglyLinkedList::popAt(int index) {
    if(index < 0 || index >= size) {            //przypadek gdy jest poza zakresem
        return;
    }

    if(index == 0) {                            //przypadek gdy chcemy usunąć pierwszy element
        popFront();
        return;
    }

    if(index == size - 1) {                     //przypadek gdy chcemy usunąć ostatni element
        popBack();
        return;
    }

    SNode* current = head;
    for(int i = 0; i < index - 1; i++) {        //iterujemy aż do elementu PRZED miejscem gdzie chcemy wstawić
        current = current->next;
    }

    SNode* toDelete = current->next;            //tworzymy tymczasowy wskaźnik na element do usunięcia, jako następny element
    current->next = toDelete->next;             //podmieniamy next z currenta na next toDelete (wskaźnik na "następniejszy" element)

    if(toDelete == tail) {
        tail = current;                         //sprawdzamy czy toDelete nie był tailem, jeśli tak to ustawiamy current tailem
    }

    delete toDelete;                            //usuwamy toDelete (węzeł który de facto mieliśmy usunąć)
    size--;                                     //zmniejszamy size
}

int SinglyLinkedList::find(int value) const {
    SNode* current = head;
    int index = 0;                              //index węzła w którym się znajdujemy (notabene head)
    
    while(current != nullptr) {                 //iterujemy do końca tablicy
        if(current->value == value) {           //sprawdzamy czy current(value) to value którego szukamy
            return index;                       //jeśli tak to zwracamy zmienną index która jest indexem węzła w którym jesteśmy
        }
        current = current->next;                //jeśli nie to przechodzimy do następnego
        index++;                                //i zwiększamy index
    }
    return -1;                                  //jeśli nie udało się znaleźć, zwracamy -1
}

//-------------------------DODATKOWE FUNKCJONALNOŚCI DLA TESTÓW I CZYTELNOŚCI ;PP------------------------------------------------

void SinglyLinkedList::print() const {
    SNode* current = head;

    cout << "[";
    while(current != nullptr) {
        cout << current->value;
        if(current->next != nullptr) {
            cout << ", ";
        }
        current = current->next;
    }
    cout << "]" << endl;
}

void SinglyLinkedList::clear() {
    SNode* current = head;

    while(current != nullptr) {
        SNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//-------------------------ZŁOŻONOŚĆ OBLICZENIOWA, KOMENTARZY KILKA------------------------------------------------

/*
pushFront - O(1) - dodajemy na początek, nic nie iterujemy
pushBack - O(1) - dodajemy na koniec, mamy tail więc idzie to szybko
pushAT - O(n) - musimy dojść do elementu w najgorszym przypadku size - 1
popFront - O(1) - usuwamy pierwszy element, na który mamy head
popBack - O(n) - usuwamy ostatni element, ale musimy znaleźć przedostatni, żeby "przepiąć" taila
popAt - O(n) - musimy dojść do elementu w najgorszym przypadku size - 1
find - O(n) - musimy dojść do elementu w najgorszym przypadku size
clear - O(n) - musimy usunąć każdy element
print - O(n) - musimy wyświetlić każdy element


myślałem nad dodaniem wyjątku do find(value) by sprawdzać od razu taila ale to nie ma sensu bo w znacznej większości
przypadków i tak musimy sprawdzić czy element jest w ogóle w liście i czy np nie jest PRZEDostatni, a wtedy
do ostatniego już krótka droga. Uważam że nie ma to sensu większego a tylko komplikuje. 
W najlepszym przypadku dodamy jednorazowe wyjątki O(1) do wielkiego morza O(n) co nic nie zmieni xpp
*/