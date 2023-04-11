#ifndef CHILD
#define CHILD

#include <iostream>
#include<cstring>

using namespace std;

class Child{

 public:
  Child(int inputValue);//constructor
  ~Child();//destructor
  
  void setRoot(int inputValue);//sets the root/char of tree
  int  getRoot();//sets the root/char of tree
    

 private:
  int value;//trees root value
  


};
#endif
