#ifndef STUDENT
#define STUDENT
#include <iostream>
#include<cstring>

using namespace std;

class Student{

 public:
  Student(int inputValue);//constructor
  ~Student();//destructor
  
  void setValue(int inputValue);//sets the id of the student
  int getValue();//gets the id of the student
    

 private:
  int value;//childs value
  


};
#endif
