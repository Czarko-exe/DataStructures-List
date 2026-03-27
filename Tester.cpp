#include "Tester.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DynamicArray.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

std::vector<int> generate_data(int N, int seed) {
	std::vector<int> data(N);
	std::mt19937 rng(seed);
	std::uniform_int_distribution<int> dist(1, 10000);

	for (int i = 0; i < N; ++i) {
		data[i] = dist(rng);
	}
	return data;
}

std::vector<int> loadSeeds(const std::string filename) {
	std::vector<int> seeds;
	std::ifstream in(filename);
	int s;
	while (in >> s) {
		seeds.push_back(s);
	}
	return seeds;
}


void test_structure(std::string structure, int N, std::string operation) {
	if (!fs::exists("output"))
		fs::create_directory("output");
	//std::ofstream out("output/" + structure + "_" + operation + "_" + std::to_string(N) + ".csv");
	if (!fs::exists("output/results.csv")) {
		std::ofstream out("output/results.csv", std::ios::app);
		out << "Struktura,Operacja,Rozmiar,Seed";
		for (int i = 1; i <= 10; ++i) out << ",Time" << i;
		out << "\n";
	}
	std::ofstream out("output/results.csv", std::ios::app);
	std::vector<int> seeds = loadSeeds("seeds.txt");

	for (int seed : seeds) {
		std::vector<int> data = generate_data(N, seed);
		std::vector<long long> times;
		for (int i = 0; i < 10; ++i) {
			if (structure == "Dynamic_Array") {
				DynamicArray arr;
				for (int x : data) arr.pushBack(x);
				long long t = measure_time([&]() {
					if (operation == "pushFront") arr.pushFront(123);
					else if (operation == "pushBack") arr.pushBack(123);
					else if (operation == "pushAt") arr.pushAt(N / 2, 123);
					else if (operation == "popFront") arr.popFront();
					else if (operation == "popBack") arr.popBack();
					else if (operation == "popAt") arr.popAt(N / 2);
					else if (operation == "find") arr.find(123);
				});
				times.push_back(t);
			}
			else if (structure == "Singly_Linked_List") {
				SinglyLinkedList list;
				for (int x : data) list.pushBack(x);
				long long t = measure_time([&]() {
					if (operation == "pushFront") list.pushFront(123);
					else if (operation == "pushBack") list.pushBack(123);
					else if (operation == "pushAt") list.pushAt(N / 2, 123);
					else if (operation == "popFront") list.popFront();
					else if (operation == "popBack") list.popBack();
					else if (operation == "popAt") list.popAt(N / 2);
					else if (operation == "find") list.find(123);
					});
				times.push_back(t);
			}
			else if (structure == "Doubly_Linked_List") {
				DoublyLinkedList list;
				for (int x : data) list.pushBack(x);
				long long t = measure_time([&]() {
					if (operation == "pushFront") list.pushFront(123);
					else if (operation == "pushBack") list.pushBack(123);
					else if (operation == "pushAt") list.pushAt(N / 2, 123);
					else if (operation == "popFront") list.popFront();
					else if (operation == "popBack") list.popBack();
					else if (operation == "popAt") list.popAt(N / 2);
					else if (operation == "find") list.find(123);
					});
				times.push_back(t);
			}
		}
		out << structure << "," << operation << "," << N << "," << seed;
		for (long long t : times)
			out << "," << t;
		out << "\n";
	}
}
