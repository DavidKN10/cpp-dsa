#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* current = head;
	while (current) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
void LinkedList<T>::add(const T& item) {
	Node* newNode = new Node(item);
	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++length;
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& item) {
	if (index > length) {
		throw std::out_of_range("Index out of range");
	}
	Node* newNode = new Node(node);
	if (index == 0) {
		newNode->next = head;
		head = newNode;
		if (length == 0) {
			tail = newNode;
		}
		else {
			Node* current = head;
			for (size_t i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
			if (newNode->next == nullptr) {
				tail = newNode;
			}
		}
		++length;
	}
}

template <typename T>
void LinkedList<T>::remove(size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of range.");
	}

	Node* toDelete;
	if (index == 0) {
		toDelete = head;
		head = head->next;

		if (length == 1) {
			tail == nullptr;
		}
	}
	else {
		Node* current = head;
		for (size_t i = 0; i < index - 1; ++i) {
			current = current->next;
		}
		toDelete = current->next;
		current->next = toDelete->next;

		if (toDelete == tail) {
			tail = current;
		}
	}		
	delete toDelete;
	--length;
}

template <typename T>
T& LinkedList<T>::get(size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}

	Node* current = head;
	for (size_t i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

template <typename T>
size_t LinkedList<T>::size() const{
	return length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	return length == 0;
}

template <typename T>
void LinkedList<T>::printLinkedList() const {
	std::cout << "[";
	Node* current = head;
	while (current) {
		std::cout << current->data;
		if (current->next) {
			std::cout << ", ";
		}
			current = current->next;
	}
	std::cout << "]\n";
}

void LinkedListExample() {
	std::cout << "==================== LinkedList Testing ====================\n";
	LinkedList<int> intLL;
	intLL.add(32);
	intLL.add(3);
	intLL.add(1);
	intLL.add(20);
	intLL.add(13);
	intLL.printLinkedList();
	intLL.remove(3);
	intLL.printLinkedList();
	std::cout << "get(1) = " << intLL.get(1) << "\n";
	std::cout << "size() = " << intLL.size() << "\n";
	std::cout << "isEmpty() = " << intLL.isEmpty() << "\n";

	LinkedList<std::string> stringLL;
	stringLL.add("Hello");
	stringLL.add("world");
	stringLL.add("hi");
	stringLL.add("test");
	stringLL.add("CPP");
	stringLL.printLinkedList();
	stringLL.remove(3);
	stringLL.printLinkedList();
	std::cout << "get(3) = " << stringLL.get(3) << "\n";
	std::cout << "size() = " << stringLL.size() << "\n";
	std::cout << "isEmpty() = " << stringLL.isEmpty() << "\n";


}
