#ifndef STUDENT
#define STUDENT
#include <iostream>
#include<cstring>

using namespace std;

class Student{

 public:
  Student(int inputId,float inputGPA,string firstName,string lastName);
  ~Student();
  void setFirstName(string firstName);
  string getFirstName();
  void setLastName(string lastName);
  string getLastName();
  void setId(int inputId);
  int getId();
  void setGPA(float inputGPA);
  float getGPA();
  

 private:
  string firstName;
  string lastName;
  int id;
  float GPA;


};
#endif
