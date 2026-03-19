#pragma once

class DynamicArray {
public:
	DynamicArray(); //Konstruktor
	~DynamicArray(); //Destruktor

	void push_front(int value); //Dodaje element na początek tablicy
	void push_back(int value);	//Dodaje element na koniec tablicy
	void insert_at(int index, int value); //Dodaje element na określonej pozycji w tablicy
	void pop_front(); //Usuwa pierwszy element z tablicy
	void pop_back(); //Usuwa ostatni element z tablicy
	void remove_at(int index); //Usuwa element z określonej pozycji w tablicy
	bool find(int value) const; //Wyszukuje element w tablicy

	//int get(int index) const; //getter - zwraca wartość elementu na określonym indeksie
	//void set(int index, int value); //setter - ustawia wartość elementu na określonym indeksie

private:
	int* data; //Wskaźnik na dynamiczną tablicę
	int size; //Aktualny rozmiar tablicy
	int capacity; //Aktualna pojemność tablicy

	void resize(); //Funkcja do zmiany rozmiaru tablicy, gdy jest pełna
};