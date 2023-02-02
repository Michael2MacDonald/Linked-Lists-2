#include "main.h"
#include "node.h"
#include "student.h"


List::List(Node* node) {
	this->start = node;
}

List::List(Student* data) {
	this->start = new Node(data);
}

List::~List() {
	// Delete all nodes
	Node* node = this->start;
	while(1) {
		if (node->getNext() == nullptr) {
			delete node;
			break;
		} else {
			Node* next = node->getNext();
			delete node;
			node = next;
		}
	}
}

Node* List::getNode(int i) {
	Node* node = this->start;
	for (int j=0; j<i; j++) {
		if (node->getNext() == nullptr) {
			// error
			return nullptr;
		} else {
			node = node->getNext();
		}
	}
	return node;
}

Node* List::getStart() {
	return this->start;
}

Node* List::getEnd() {
	Node *node = this->start;
	while(1) {
		if (node->getNext() == nullptr) {
			return node;
		} else { node = node->getNext(); }
	}
}

int List::size() {
	int i = 1;
	Node *node = this->start;
	while(1) {
		if (node->getNext() == nullptr) {
			return i;
		} else {
			node = node->getNext();
			i++;
		}
	}
}

Node* List::operator[](int i) {
    return this->getNode(i);
}

void List::addNode(Node* node) {
	// Check if the given node is already part of a list
	// This does not work in the node is at the end of a list
	// We need to implement a 'previous' or 'start' varuable so the entire list can be found from any node
	if (node->getNext() != nullptr) return;
	
	// Check if the list is empty
	if (this->start == nullptr) {
		this->start = node; // Make the node the first node
	} else {
		Node* end = this->getEnd(); // get the last node
		end->setNext(node); // append the node to the last node
	}
}

void List::delNode(int i) {
	// Get the node to delete
	Node* node = this->getNode(i);
	
	// Check if the node is the start node
	if (i == 0) this->start = node->getNext(); // set new start
	// Set the previous node's 'next' to this node's 'next' to remove this node from the chain
	else this->getNode(i-1)->setNext( node->getNext() );
	
	delete node; // delete!!!!
}



