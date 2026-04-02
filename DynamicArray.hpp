#pragma once

class DynamicArray {
public:
	DynamicArray(); //Konstruktor
	~DynamicArray(); //Destruktor

	void pushFront(int value); //Dodaje element na początek tablicy
	void pushBack(int value);	//Dodaje element na koniec tablicy
	void pushAt(int index, int value); //Dodaje element na określonej pozycji w tablicy
	
	void popFront(); //Usuwa pierwszy element z tablicy
	void popBack(); //Usuwa ostatni element z tablicy
	void popAt(int index); //Usuwa element z określonej pozycji w tablicy
	
	int find(int value) const; //Wyszukuje element w tablicy
	void print() const; //Funkcja do wyświetlania zawartości tablicy (do testów)

	int getSize() const; //Zwraca aktualny rozmiar tablicy
	int get(int index) const;	//Zwraca wartość elementu na określonym indeksie

private:
	int* data; //Wskaźnik na dynamiczną tablicę
	int size; //Aktualny rozmiar tablicy
	int capacity; //Aktualna pojemność tablicy

	void resize(); //Funkcja do zmiany rozmiaru tablicy, gdy jest pełna
};