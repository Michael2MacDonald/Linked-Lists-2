#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

class Node {
    public:
    //constructor and destructor
    Node(Student* student);
    ~Node();
    //get student
    Student* getStudent();
    //set and get next
    void setNext(Node* newnext);
    Node* getNext();
    
    private:
    Student* student;
    Node* pNext;
};
#endif