
#include<iostream>
#include"node.h"

using namespace std;

node::node(student* newStudent){
  theStudent = newStudent;
  next = NULL;
}

node::~node(){
  delete theStudent;
  next = NULL; 
}
void node::setNext(node* nextNode){

  next = nextNode;
}

node* node::getNext(){
  return next;
}

void node::setPrevious(node* previousNode){
  previous = previousNode;
}
node* node::getPrevious(){
  return previous;
}

student* node::getStudent(){
  return theStudent;
}
