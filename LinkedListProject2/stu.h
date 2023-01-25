#ifndef STUDENT
#define STUDENT
#include <iostream>
#include<cstring>


class Student{

 public:
  Student(int inputId);
  ~Student();
  void setFirstName();
  char getFirstName();
  void setLastName();
  char getLastName();
  void setId(int inputId);
  int getId();
  void setGPA();
  float getGPA();
  

 private:
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;


};
#endif
