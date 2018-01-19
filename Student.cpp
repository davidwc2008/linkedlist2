#include <iostream>
#include "Student.h"

using namespace std;

//constructor
Student::Student(char* name_f, char* name_l, int ID, float GPA) {
  first_name = name_f;
  last_name = name_l;
  id = ID;
  gpa= GPA;
}

//deconstructor
Student::~Student() {
  delete first_name;
  delete last_name;
  //don't delete others that are not primitives
}

//getname_f function
char* Student::getname_f() { 
  return first_name;
}

//getname_l function
char* Student::getname_l() {
  return last_name;
}

//getid function
int Student::getid() {
  return id;
}

//getgpa function
float Student::getgpa() {
  return gpa;
}
