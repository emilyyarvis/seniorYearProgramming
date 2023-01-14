#ifndef NODE
#define NODE

#include<iostream>
#include"student.h"

using namespace std;

class node{

 public:
  node(student*);//node constructor
  ~node();//node destructor
  void setNext(node*);//sets a nodes next node
  node* getNext();//gets a nodes next node
  void setPrevious(node*);//sets a nodes previous node
  node* getPrevious();//gets a nodes previous node
  student* getStudent();//gets the student associated with the node
 private:
  node* next;//the nodes next node
  student* theStudent;//the nodes associated student
  node* previous;//the nodes previous node
};
#endif
