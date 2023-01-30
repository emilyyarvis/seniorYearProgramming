#ifndef STUDENT
#define STUDENT
#include <iostream>
#include<cstring>

using namespace std;

class Student{

 public:
  Student(int inputId,float inputGPA,string firstName,string lastName);//constructor
  ~Student();//destructor
  void setFirstName(string firstName);//sets the first name of student
  string getFirstName();//gets the frst name of student
  void setLastName(string lastName);//sets the last name of student
  string getLastName();//gets the last name of student
  void setId(int inputId);//sets the id of the student
  int getId();//gets the id of the student
  void setGPA(float inputGPA);//sets the GPA of the student
  float getGPA();//gets the GPA of the student
  

 private:
  string firstName;//students first name
  string lastName;//students last name
  int id;//students id
  float GPA;//students GPA


};
#endif
