#include "DynamicArray.h"
#include <algorithm>

DynamicArray::DynamicArray() : data(nullptr), size(0), capacity(4) {} // Konstruktor inicjalizujący wskaźnik na tablicę jako nullptr, rozmiar jako 0 i pojemność jako 4

DynamicArray::~DynamicArray() { // Destruktor zwalniający pamięć zajmowaną przez tablicę
	delete[] data;
}

void DynamicArray::push_front(int value) {
	if (size == capacity) { // Sprawdzamy czy tablica jest pełna
		resize(); // Jeśli tak, to zwiększamy jej pojemność
	}
	for (int i = size; i > 0; --i) { // Przesuwamy wszystkie elementy o jedno miejsce w prawo
		data[i] = data[i - 1];
	}
	data[0] = value; // Dodajemy nowy element na początek tablicy
	size++; // Zwiększamy rozmiar
}

void DynamicArray::push_back(int value) {
	if (size == capacity) { // Sprawdzamy czy tablica jest pełna
		resize(); // Jeśli tak, to zwiększamy jej pojemność
	}
	data[size++] = value; // Dodajemy nowy element na koniec tablicy i zwiększamy rozmiar
}

//Dodać insert_at ----------------------------------------------------

void DynamicArray::pop_front() {
	if (size > 0) {
		for (int i = 0; i < size - 1; ++i) { // Przesuwamy wszystkie elementy o jedno miejsce w lewo
			data[i] = data[i + 1];
		}
		size--; // Zmniejszamy rozmiar
	}
}

void DynamicArray::pop_back() {
	if (size > 0) {
		size--; // Zmniejszamy rozmiar, usuwając ostatni element
	}
}

//Dodać remove_at ----------------------------------------------------

bool DynamicArray::find(int value) const {
	for (int i = 0; i < size; ++i) { // Przeszukujemy tablicę w poszukiwaniu wartości
		if (data[i] == value) {
			return true; // Jeśli znajdziemy, zwracamy true
		}
	}
	return false; // Jeśli nie znajdziemy, zwracamy false
}

void DynamicArray::resize() {
	if (capacity == 0) {
		capacity = 1; // Jeśli pojemność jest 0, ustawiamy ją na 1
	} else {
		capacity *= 2; // Podwajamy pojemność
	}

	int* newData = new int[capacity]; // Tworzymy nową tablicę o zwiększonej pojemności
	std::copy(data, data + size, newData); // Kopiujemy stare dane do nowej tablicy
	delete[] data; // Zwalniamy pamięć zajmowaną przez starą tablicę
	data = newData; // Ustawiamy wskaźnik na nową tablicę
}