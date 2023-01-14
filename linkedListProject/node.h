#ifndef NODE
#define NODE

#include<iostream>
#include"student.h"

using namespace std;

class node{

 public:
  node(student*);
  ~node();
  void setNext(node*);
  node* getNext();
  void setPrevious(node*);
  node* getPrevious();
  student* getStudent();
 private:
  node* next;
  student* theStudent;
  node* previous;
};
#endif
