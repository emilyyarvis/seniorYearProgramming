
#include<iostream>
#include"newNode.h"

using namespace std;

Node::Node(Student* newStudent){
  student=newStudent;
  left=NULL;
  right = NULL;
}

Node::~Node(){
  delete student;
  left =NULL;
  right = NULL;
  next = NULL;
}

Student* Node::getStudent(){
  return student;
}

void Node::setNext(Node* node){
  next=node;
}
Node* Node::getNext(){
  return next;
}

void Node::setRight(Node* node){
  right=node;
}
void Node::setLeft(Node* node){
  left=node;
}

Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}

