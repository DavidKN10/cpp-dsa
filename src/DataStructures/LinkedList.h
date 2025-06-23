#pragma once

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& value) : data(value), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	size_t length;
public:
	LinkedList();
	~LinkedList();

	void add(const T& item);
	void insert(size_t index, const T& item);
	void remove(size_t index);
	T& get(size_t index);
	size_t size() const;
	bool isEmpty() const;
	void printLinkedList() const;
};

void LinkedListExample();