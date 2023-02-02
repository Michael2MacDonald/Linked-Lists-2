#include "node.h"


Node::Node(Student* newstudent) {//constructor
    pNext = NULL;
    student = newstudent;
}

Node::~Node() {//destructor
    delete &student;
    pNext = NULL;
}

Student* Node::getStudent() {//get (set already done with constructor.)
    return student;
}

//get and set next
void Node::setNext(Node* newnext) {
    pNext = newnext;
}

Node* Node::getNext() {
    return pNext;
}