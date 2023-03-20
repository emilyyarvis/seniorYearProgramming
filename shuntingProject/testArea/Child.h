#ifndef CHILD
#define CHILD

#include <iostream>
#include<cstring>

using namespace std;

class Child{

 public:
  Child(char inputValue);//constructor
  ~Child();//destructor
  
  void setRoot(char inputValue);//sets the root/char of tree
  char getRoot();//sets the root/char of tree
    

 private:
  char value;//trees root value
  


};
#endif
