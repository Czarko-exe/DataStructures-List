#include "DynamicArray.hpp"
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

void DynamicArray::push_at(int index, int value) {
	if (index == 0) {	// Jeśli indeks to 0, dodajemy element na początek tablicy
		push_front(value);
	}
	else if (index == size) {	// Jeśli indeks to rozmiar, dodajemy element na koniec tablicy
		push_back(value);
	}
	else {
		if (size == capacity) {
			resize();
		}
		for (int i = size; i > index; i++) {	// Przesuwamy wszystkie elementy od indeksu do końca o jedno miejsce w prawo
			data[i] = data[i - 1];
		}
		data[index] = value;
	}
}

void DynamicArray::pop_front() {
	if (size > 0) {
		for (int i = 0; i < size - 1; i++) { // Przesuwamy wszystkie elementy o jedno miejsce w lewo
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

void DynamicArray::pop_at(int index) {
	if (index == 0) {	// Jeśli indeks to 0, usuwamy element z początku tablicy
		pop_front();
	}
	else if (index == size) {	// Jeśli indeks to rozmiar, usuwamy element z końca tablicy
		pop_back();
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

	int* newData = new int[capacity]; // Tworzymy nową tablicę o zwiększonej pojemności
	std::copy(data, data + size, newData); // Kopiujemy stare dane do nowej tablicy
	delete[] data; // Zwalniamy pamięć zajmowaną przez starą tablicę
	data = newData; // Ustawiamy wskaźnik na nową tablicę
}