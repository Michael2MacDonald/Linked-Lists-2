#ifndef MAIN_H
#define MAIN_H

#include "node.h"
#include "student.h"

class List {
private:
	Node* start;
public:
	List(Node*); // Create list and set start node
	List(Student*); // Create List and create new start node with provided data
	~List(); // Delete list and all nodes
	
	Node* getNode(int); // Get node pointer by index
	Node* getStart(); // Get node pointer for the start node
	Node* getEnd(); // Get node pointer for the end node
	
	int size(); // Get size
	
	void addNode(Node*); // Add node to end of list
	void delNode(int i); // Delete node at index i
	
	// Overloading [] operator to access elements in array style
	Node* operator[](int);
};


#endif /* MAIN_H */