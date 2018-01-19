#pragma once

#include <iostream>

#include "Student.h"

using namespace std;

//Node class includes Node pointer, getNext Node, getStudent and setNext Node functions 
class Node {
 public:
  Node(Student* student);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);

 private:
  Student* student;
  Node* next;
};
