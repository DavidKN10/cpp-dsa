#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList {
private:
	T* data;
	size_t capacity;
	size_t length;

	void resize();

public:
	ArrayList(size_t initialCapacity = 10);

	~ArrayList();

	void add(const T& item);
	void insert(size_t index, const T& item);
	void remove(size_t index);
	T& get(size_t index);
	size_t size() const;
	bool isEmpty() const;
	void printArrayList() const;
};

void ArrayListExample();
