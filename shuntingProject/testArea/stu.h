#ifndef STUDENT
#define STUDENT
#include <iostream>
#include<cstring>

using namespace std;

class Student{

 public:
  Student(char inputValue);//constructor
  ~Student();//destructor
  
  void setValue(char inputValue);//sets the id of the student
  char getValue();//gets the id of the student
    

 private:
  char value;//childs value
  


};
#endif
