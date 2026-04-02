#include "Tester.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DynamicArray.hpp"
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

// Funkcja do generowania losowych danych na podstawie ziarna
DynamicArray generate_data(int N, int seed) {
	DynamicArray data;
	std::mt19937 rng(seed);
	std::uniform_int_distribution<int> dist(1, 10000);	// Zakres losowanych liczb

	for (int i = 0; i < N; ++i) {
		data.pushBack(dist(rng));	// Generujemy losową liczbę i zapisujemy ją do wektora
	}
	return data;
}

// Funkcja do wczytywania ziaren z pliku
DynamicArray loadSeeds(const std::string filename) {
	DynamicArray seeds;
	std::ifstream in(filename);
	int s;
	while (in >> s) {
		seeds.pushBack(s);	// Wczytujemy kolejne ziarna z pliku i zapisujemy je do wektora
	}
	return seeds;
}

// Funkcja do testowania struktury danych i operacji
void test_structure(std::string structure, int N, std::string operation) {
	if (!fs::exists("output"))
		fs::create_directory("output");	// Tworzymy katalog output, jeśli nie istnieje

	// Jeśli plik results.csv nie istnieje, tworzymy go i zapisujemy nagłówki kolumn
	if (!fs::exists("output/results.csv")) {
		std::ofstream out("output/results.csv", std::ios::app);	// Otwieramy plik w trybie dopisywania, ale ponieważ plik nie istnieje, zostanie utworzony
		out << "Struktura,Operacja,Rozmiar,Seed";
		for (int i = 1; i <= 10; ++i) out << ",Time" << i;
		out << "\n";
	}
	std::ofstream out("output/results.csv", std::ios::app);
	DynamicArray seeds = loadSeeds("seeds.txt");	// Wczytujemy ziarna z pliku seeds.txt

	for (int s_idx = 0; s_idx < seeds.getSize(); ++s_idx) {	// Dla każdego ziarna generujemy dane i mierzymy czas wykonania operacji
		int seed = seeds.get(s_idx);
		DynamicArray data = generate_data(N, seed);	// Generujemy dane na podstawie ziarna
		long long times[10] = {};

		for (int i = 0; i < 10; ++i) {
			if (structure == "Dynamic_Array") {
				DynamicArray arr;
				for (int d_idx = 0; d_idx < data.getSize(); ++d_idx) arr.pushBack(data.get(d_idx));	// Wypełniamy strukturę danymi przed testem
				long long t = measure_time([&]() {	// Mierzymy czas wykonania operacji
					if (operation == "pushFront") arr.pushFront(123);
					else if (operation == "pushBack") arr.pushBack(123);
					else if (operation == "pushAt") arr.pushAt(N / 2, 123);
					else if (operation == "popFront") arr.popFront();
					else if (operation == "popBack") arr.popBack();
					else if (operation == "popAt") arr.popAt(N / 2);
					else if (operation == "find") arr.find(123);
				});
				times[i] = t;	// Zapisujemy zmierzony czas do times
			}
			else if (structure == "Singly_Linked_List") {	// Analogicznie dla listy jednokierunkowej
				SinglyLinkedList list;
				for (int d_idx = 0; d_idx < data.getSize(); ++d_idx) list.pushBack(data.get(d_idx));
				long long t = measure_time([&]() {
					if (operation == "pushFront") list.pushFront(123);
					else if (operation == "pushBack") list.pushBack(123);
					else if (operation == "pushAt") list.pushAt(N / 2, 123);
					else if (operation == "popFront") list.popFront();
					else if (operation == "popBack") list.popBack();
					else if (operation == "popAt") list.popAt(N / 2);
					else if (operation == "find") list.find(123);
					});
				times[i] = t;
			}
			else if (structure == "Doubly_Linked_List") {	// Analogicznie dla listy dwukierunkowej
				DoublyLinkedList list;
				for (int d_idx = 0; d_idx < data.getSize(); ++d_idx) list.pushBack(data.get(d_idx));
				long long t = measure_time([&]() {
					if (operation == "pushFront") list.pushFront(123);
					else if (operation == "pushBack") list.pushBack(123);
					else if (operation == "pushAt") list.pushAt(N / 2, 123);
					else if (operation == "popFront") list.popFront();
					else if (operation == "popBack") list.popBack();
					else if (operation == "popAt") list.popAt(N / 2);
					else if (operation == "find") list.find(123);
					});
				times[i] = t;
			}
		}
		out << structure << "," << operation << "," << N << "," << seed;	// Zapisujemy wyniki do pliku CSV
		for (int i = 0; i < 10; ++i) out << "," << times[i];
		out << "\n";
	}
}
