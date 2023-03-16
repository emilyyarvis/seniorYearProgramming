#ifndef CHILD
#define CHILD

#include <iostream>
#include<cstring>

using namespace std;

class Child{

 public:
  Child(char inputValue);//constructor
  ~Child();//destructor
  
  void setRoot(char inputValue);//sets the id of the student
  char getRoot();//gets the id of the student
    

 private:
  char value;//trees root value
  


};
#endif
