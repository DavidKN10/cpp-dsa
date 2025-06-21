#include "ArrayList.h"

template <typename T>
void ArrayList<T>::resize() {
	capacity *= 2;
	T* newData = new T[capacity];
	for (size_t i = 0; i < length; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

template <typename T>
ArrayList<T>::ArrayList(size_t initialCapacity) {
	capacity = initialCapacity;
	length = 0;
	data = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
	delete[] data;
}

template <typename T>
void ArrayList<T>::add(const T& item) {
	if (length == capacity) {
		resize();
	}
	data[length++] = item;
}

template <typename T>
void ArrayList<T>::insert(size_t index, const T& item) {
	if (index > length) {
		std::out_of_range("Index out of range");
	}
	if (length == capacity) {
		resize();
	}
	for (size_t i = length; i < index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = item;
	++length;
}

template <typename T>
void ArrayList<T>::remove(size_t index) {
	if (index > length) {
		throw std::out_of_range("Index out of range");
	}
	for (size_t i = index; i < length - 1; ++i) {
		data[i] = data[i + 1];
	}
	--length;
}

template <typename T>
T& ArrayList<T>::get(size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

template <typename T>
size_t ArrayList<T>::size() const {
	return length;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
	if (length == 0) {
		return true;
	}
	else return false;
}

template <typename T>
void ArrayList<T>::printArrayList() const {
	std::cout << "[";
	for (size_t i = 0; i < length; ++i) {
		std::cout << data[i];
		if (i != length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

void ArrayListExample() {
	ArrayList<int> intList;
	intList.add(1);
	intList.add(2);
	intList.add(3);
	intList.add(4);
	intList.printArrayList();
	intList.remove(3);
	intList.printArrayList();
	std::cout << "get(2) = " << intList.get(2) << "\n";
	std::cout << "size() = " << intList.size() << "\n";
	std::cout << "isEmpty() = " << intList.isEmpty() << "\n";

	ArrayList<std::string> stringList;
	stringList.add("hello");
	stringList.add("world");
	stringList.add("hi");
	stringList.printArrayList();
	stringList.remove(2);
	stringList.printArrayList();
	std::cout << "get(1) = " << stringList.get(1) << "\n";
	std::cout << "size() = " << stringList.size() << "\n";
	std::cout << "isEmpty() = " << stringList.isEmpty() << "\n";
}