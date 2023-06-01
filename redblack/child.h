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

  char getColor();
  void setColor(char inputColor);

  bool getNull();
  void setNull(bool inputNull);

 private:
  int value;//trees root value
  char color;
  bool nullity;


};
#endif
