#include<iostream>
#include"student.h"

using namespace std;

class node{

 public:
  node(student*);
  ~node();
  void setNext(node*);
  node* getNext();
  student* getStudent();
 private:
  node* next;
  student* theStudent;
};
