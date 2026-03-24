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
	std::ofstream out("output/" + structure + "_" + operation + "_" + std::to_string(N) + ".csv");

	std::vector<int> seeds = loadSeeds("seeds.txt");
	for (int seed : seeds) {
		std::vector<int> data = generate_data(N, seed);
		if (structure == "Dynamic_Array") {
			DynamicArray arr;
			for (int x : data) {
				arr.push_back(x);
			}
			arr.print();
		} else if (structure == "Singly_Linked_List") {
			SinglyLinkedList list;
			for (int x : data) {
				list.pushBack(x);
			}
			list.print();
		} else if (structure == "Doubly_Linked_List") {
			DoublyLinkedList list;
			for (int x : data) {
				list.pushBack(x);
			}
			list.print();
		}
	}

}