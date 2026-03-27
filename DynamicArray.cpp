#include "DynamicArray.hpp"
#include <algorithm>
#include <iostream>

DynamicArray::DynamicArray() : data(nullptr), size(0), capacity(0) {} // Konstruktor inicjalizujący wskaźnik na tablicę jako nullptr, rozmiar jako 0 i pojemność jako 4

DynamicArray::~DynamicArray() { // Destruktor zwalniający pamięć zajmowaną przez tablicę
	delete[] data;
}

void DynamicArray::pushFront(int value) {
	if (size == capacity) { // Sprawdzamy czy tablica jest pełna
		resize(); // Jeśli tak, to zwiększamy jej pojemność
	}
	for (int i = size - 1; i >= 0; --i) { // Przesuwamy wszystkie elementy o jedno miejsce w prawo
		data[i+1] = data[i];
	}
	data[0] = value; // Dodajemy nowy element na początek tablicy
	size++; // Zwiększamy rozmiar
}

void DynamicArray::pushBack(int value) {
	if (size == capacity) { // Sprawdzamy czy tablica jest pełna
		resize(); // Jeśli tak, to zwiększamy jej pojemność
	}
	data[size++] = value; // Dodajemy nowy element na koniec tablicy i zwiększamy rozmiar
}

void DynamicArray::pushAt(int index, int value) {
	if (index < 0 || index > size) return;
	if (index == 0) {	// Jeśli indeks to 0, dodajemy element na początek tablicy
		pushFront(value);
	}
	else if (index == size) {	// Jeśli indeks to rozmiar, dodajemy element na koniec tablicy
		pushBack(value);
	}
	else {
		if (size == capacity) {
			resize();
		}
		for (int i = size; i > index; --i) {	// Przesuwamy wszystkie elementy od indeksu do końca o jedno miejsce w prawo
			data[i] = data[i - 1];
		}
		data[index] = value;
		++size;
	}
}

void DynamicArray::popFront() {
	if (size > 0) {
		for (int i = 0; i < size - 1; i++) { // Przesuwamy wszystkie elementy o jedno miejsce w lewo
			data[i] = data[i + 1];
		}
		size--; // Zmniejszamy rozmiar
	}
}

void DynamicArray::popBack() {
	if (size > 0) {
		size--; // Zmniejszamy rozmiar, usuwając ostatni element
	}
}

void DynamicArray::popAt(int index) {
	if (index == 0) {	// Jeśli indeks to 0, usuwamy element z początku tablicy
		popFront();
	}
	else if (index == size) {	// Jeśli indeks to rozmiar, usuwamy element z końca tablicy
		popBack();
	}
	else {
		for (int i = index; i < size - 1; i++) {	// Przesuwamy wszystkie elementy od indeksu do końca o jedno miejsce w lewo
			data[i] = data[i + 1];
		}
		size--;
	}
}

int DynamicArray::find(int value) const {
	for (int i = 0; i < size; ++i) { // Przeszukujemy tablicę w poszukiwaniu wartości
		if (data[i] == value) {
			return i; // Jeśli znajdziemy, zwracamy indeks
		}
	}
	return -1; // Jeśli nie znajdziemy, zwracamy indeks
}

void DynamicArray::resize() {
	if (capacity == 0) {
		capacity = 1; // Jeśli pojemność jest 0, ustawiamy ją na 1
	} else {
		capacity *= 2; // Podwajamy pojemność
	}

	int* newData = new int[capacity];
	if (data) {
	    std::copy(data, data + size, newData);
	}
	delete[] data;
	data = newData;
}



void DynamicArray::print() const {
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << " "; // Wyświetlamy zawartość tablicy
	}
	std::cout << std::endl;
}