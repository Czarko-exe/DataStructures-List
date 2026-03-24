#pragma once
#include <vector>
#include <string>

std::vector<int> generate_data(int N, int seed);
std::vector<int> loadSeeds(const std::string filename);
void test_structure(std::string structure, int N, std::string operation);