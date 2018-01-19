#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

//student class
class Student {
 public:
  Student(char*, char*, int, float); //constructor
  ~Student(); //deconstructor

  //miscellaneous functions
  char* getname_f();
    char* getname_l();
    int getid();
    float getgpa();
    
 protected:
    char* first_name;
    char* last_name;
    int id;
    float gpa;
};
#endif
  
