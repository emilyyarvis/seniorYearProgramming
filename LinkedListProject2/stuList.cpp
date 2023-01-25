#include <iostream>
#include "newNode.h"

void add(int userId,Node* &firstNode);
void print(Node* firstNode);
void sort(Node* &firstNode);
using namespace std;

int main(){

  Student* joe = new Student(2);
  cout<< joe->getId()<<endl;
  Node* test = new Node(joe);
  cout<<test->getStudent()->getId()<<endl;
  add(33, test);
  print(test);
  add(44, test);
  print(test);


}
void sort(Node* &firstNode){

}


void add(int userId,Node* &firstNode){
  Node* current = firstNode;
  Node*temporary;
  int newId;
  if(current== NULL){
    firstNode = new Node(new Student(userId));
  }
  else{
    temporary = current;
    while(current->getNext()!=NULL){
      temporary = current;
      current = current->getNext();
    }
    // current->setPrevious(temporary);
    current->setNext(new Node(new Student(userId)));
    // current->getNext()->setPrevious(current);
  }
}

void print(Node* firstNode){
  Node* printNode = firstNode;
  Node* temp;
  cout<<endl;
  while(printNode->getNext()!=NULL){
    if(printNode->getStudent()->getId() ==0){
      printNode = printNode->getNext();
    }
    else{
      cout<<printNode->getStudent()->getId()<<endl;
      printNode = printNode->getNext();
    }
  }
    
  cout<<printNode->getStudent()->getId()<<endl;

}
