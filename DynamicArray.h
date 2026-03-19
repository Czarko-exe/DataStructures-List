#pragma once

class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();
	void push_back(int value);
	int get(size_t index) const;
	size_t size() const;
};