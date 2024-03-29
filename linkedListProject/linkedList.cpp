#include<iostream>
#include"node.h"
//#include"student.h"
using namespace std;

void add(int userId,node* &firstNode);
void print(node* firstNode);
void deleter(int deletedId,node* &head);

int main(){

  student* joe = new student(1);
  node* test=new node(joe);
  node* first= NULL;
  add(22,first);
  //print(first);
  add(15,first);
  //print(first);
  add(17,first);
  add(55,first);
  add(700,first);
  add(666,first);
  print(first);
  deleter(55,first);
  print(first);
  deleter(22,first);
  print(first);
  deleter(666,first);
  print(first);
}

void add(int userId,node* &firstNode){
  node* current = firstNode;
  node*temporary;
  int newId;
  if(current== NULL){
    firstNode = new node(new student(userId));
  }
  else{
    temporary = current;
    while(current->getNext()!=NULL){
      temporary = current;
      current = current->getNext();
    }
    current->setPrevious(temporary);
    current->setNext(new node(new student(userId)));
    current->getNext()->setPrevious(current);
  }
}

void print(node* firstNode){
  node* printNode = firstNode;
  node* temp;
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

void deleter(int deletedId,node* &head){
  node* current = head;
  node*found;
  
  if(current->getStudent()->getId() ==deletedId){
    head = head->getNext();
    current->~node();
  }
  
  while (current->getNext()!=NULL){
    current = current->getNext();
    if(current->getNext()==NULL){
      if(current->getStudent()->getId() == deletedId){
	current->getPrevious()->setNext(NULL);
	current->~node();
      }
    }
    else{
      if(current->getStudent()->getId() == deletedId){
	current->getPrevious()->setNext(current->getNext());
	current->~node();
	
      }
    }
  }
     
}
