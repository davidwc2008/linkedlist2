/*
David Chen
2018
Student List Program Using Linked Lists in C++
*/

#include <iostream>
#include <cstring> //for string compare and other operations
#include <iomanip> //for gpa precision
#include "Node.h" // partner's header file
#include "Student.h" //my student header file

using namespace std;

//function declarations
void add(Student* random, Node* next, Node* &head);
void print(Node* next, Node* &head);
void remove(int id_num, Node* current, Node* &head);
void average(Node* next, double &total, int &number, Node* &head);

//main function
int main()
{
  Node* head = NULL;
  char invalid = 'y';
  char input[20] = " ";

  while (invalid == 'y') {
    cout << "Welcome to Student List.  Type ADD to add students, PRINT to print student information, DELETE to remove a student's information, AVERAGE to average gpa's, and QUIT to quit." << endl;
    cin >> input;
    if (!strcmp(input, "ADD")) {
       //the variables
      char *name_f = new char[20];
      char *name_l = new char[20];
      int ID; 
      float GPA;

      cout << "Input first name: " << endl;
      cin >> name_f;
      cout << "Input last name: " << endl;
      cin >> name_l;
      cout << "Input your id number: " << endl;
      cin >> ID;
      cout << "Input your gpa: " << endl;
      cin >> GPA;

      Student* random = new Student(name_f, name_l, ID, GPA);

      add(random, head, head);
    }else if (!strcmp(input, "PRINT")) {
      print(head, head);
    }else if (!strcmp(input, "DELETE")) {
       int id_num = 0;
       cout << "What is the id number of the student you wish to delete: ";
       cin >> id_num;
       remove(id_num, head, head);
    } else if (!strcmp(input, "AVERAGE")) {
      double avg = 0;
      double total = 0;
      int number = 0;
      average(head, total, number, head);
      avg = total/number;
      cout << setprecision(3) << avg << endl;

    } else if (!strcmp(input, "QUIT")) {
      break;
    }else {
      cout << "Invalid input.  Would you like to try again?  Press y for yes and n for no.";
      cin >> invalid;
    }
  } 

  return 0;
}

//work on functions down here
void add(Student* random, Node* next, Node* &head) {
  // make sure that students are ordered based on id number  
  if (next == NULL) {
    head = new Node(random);
    head->setNext(NULL);
  } else if (next->getStudent()->getid() > random->getid()) {
    Node* newnode = new Node(random);
    newnode->setNext(head);
    head = newnode;
  } else if ((next->getNext() == NULL) || (next->getNext()->getStudent()->getid() > random->getid())) {
    Node* newnode = new Node(random);
    newnode->setNext(next->getNext());
    next->setNext(newnode);
  } else {
    add(random,next->getNext(), head);
  }
}

//print with id number least to greatest
//remember to set precision to 2 decimal places
void print(Node* next, Node* &head) {
  if (next == head) {
    cout << "Student: "<< endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->getname_f() << " " << next->getStudent()->getname_l() << ", " << next->getStudent()->getid() << ", " << setprecision(3) << next->getStudent()->getgpa() << endl;
    print(next->getNext(), head);
  } else {
    cout << endl;
  }
}

//remove function
void remove(int id_num, Node* current, Node* &head) {
  if (current == NULL) {
    cout << "There are no students currently" << endl;
  } else if (current->getStudent()->getid() == id_num) {
    Node* todelete = head;
    head = head->getNext();
    delete todelete;
  } else if (current->getNext() == NULL) {
  } else if (current->getNext()->getStudent()->getid() == id_num) {
    Node* todelete = current->getNext();
    current->setNext(current->getNext()->getNext());
    delete todelete;
  } else {
    remove(id_num, current->getNext(), head);
  }
}

//average function
void average(Node* next, double &total, int &number, Node* &head) {
  if (next != NULL) {
    total += next->getStudent()->getgpa();
    number++;
    average(next->getNext(), total, number, head);
  }
}
