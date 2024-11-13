#include <iostream>

void* operator new(size_t size) {
	std::cout << "Allocating: " << size << " bytes" << '\n';
	return malloc(size);
}

void operator delete(void* memory, size_t size) {
	std::cout << "Freeing: " << size << " bytes" << '\n';
	free(memory);
}

template <typename T>
class Node {
private:
	T val;
	Node<T>* next;

public:
	Node() {
		val = 0;
		next = NULL;
	}

	Node(T val) {
		this->val = val;
		this->next = NULL;
	}

	Node<T>* getNext() {
		return next;
	}

	void setNext(Node<T>* next) {
		this->next = next;
	}

	T getVal() {
		return val;
	}

	void setVal(T val) {
		this->val = val;
	}

	friend std::ostream& operator<<(std::ostream& os, Node<T> node) {
		os << node.getVal();
		return os;
	}
};

template <typename T>
class LinkedList {
private:
	Node<T> head;

public:
	LinkedList(T val) {
		head.setVal(val);
	}

	Node<T> getHead() {
		return head;
	}

	void addNode(T val, int pos = -1) {
		Node<T>* newNode = new Node<T>;
		newNode->setVal(val);
		newNode->setNext(NULL);
		Node<T>* currentNode = &head;
		while(currentNode->getNext() != NULL) { currentNode = currentNode->getNext(); }
		currentNode->setNext(newNode);
	}

	void removeNode(int pos = -1) {
		Node<T>* currentNode = &head;
		while(currentNode->getNext()->getNext() != NULL) { currentNode = currentNode->getNext(); }
		delete currentNode->getNext();
		currentNode->setNext(NULL);
	}

	void printNodes() {
		Node<T> currentNode = head;
		std::cout << currentNode << '\n';
		while(currentNode.getNext() != NULL) {
			currentNode = *(currentNode.getNext());
			std::cout << currentNode.getVal() << '\n';
		}
	}

	~LinkedList() {
		Node<T>* current = head.getNext();
		while(current != NULL) {
			Node<T>* next = current->getNext();
			delete current;
			current = next;
		}
	}
};

int main() {
	LinkedList<int> list(5);
	list.addNode(6);
	list.removeNode();
	list.addNode(7);
	list.printNodes();
}
