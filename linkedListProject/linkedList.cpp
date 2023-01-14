#include<iostream>
#include"node.h"
//#include"student.h"
using namespace std;

void add(int userId,node* &firstNode);
void print(node* firstNode);
void deleter(int deletedId,node* head);

int main(){

  student* joe = new student(1);
  node* test=new node(joe);
  node* first= NULL;
  add(22,first);
  //cout<<first->getStudent()->getId()<<endl;
  //print(first);
  add(15,first);
  //print(first);
  add(17,first);
  add(55,first);
  add(700,first);
  add(666,first);
  //print(first);
  cout<<first->getNext()->getPrevious()->getStudent()->getId()<<endl;
  deleter(55,first);
  print(first);
  // cout<<"right file?"<<endl;
  // first->getNext()->~node();
  // print(first);
}

void add(int userId,node* &firstNode){
  node* current = firstNode;
  node*temporary;
  int newId;
  if(current== NULL){
    firstNode = new node(new student(userId));
    //cout<<userId<<endl;
  }
  else{
    temporary = current;
    while(current->getNext()!=NULL){
      //cout<<"HELLO"<<endl;
      temporary = current;
      current = current->getNext();
    }
    //cout<<temporary->getPrevious()->getStudent()->getId()<<endl;
    current->setPrevious(temporary);//cout<<"Idid it"<<endl;
    current->setNext(new node(new student(userId)));
    //cout<<current->getNext()->getStudent()->getId()<<endl;
    //cout<<current->getPrevious()->getStudent()->getId()<<endl;
    //cout<<endl;
  }
}

void print(node* firstNode){
  node* printNode = firstNode;
  node* temp;
  cout<<endl;
  while(printNode->getNext()!=NULL){
    if(printNode->getStudent()->getId() ==0){
      cout<<"HELOOO"<<endl;
      printNode = printNode->getNext();
    }
    else{
      cout<<printNode->getStudent()->getId()<<endl;
      //      cout<<printNode->getPrevious()->getStudent()->getId()<<endl;
      
      printNode = printNode->getNext();
    }
  }
    
  cout<<printNode->getStudent()->getId()<<endl;

}

void deleter(int deletedId,node* head){
  node* current = head;
  node*found;
  
  if(current->getStudent()->getId() ==deletedId){
    current->getPrevious()->setNext(current->getNext());
    current->~node();
  }
  
  while (current->getNext()!=NULL){
    current = current->getNext();
    if(current->getStudent()->getId() == deletedId){
      cout<<"SUCCESS"<<endl;
      current->getPrevious()->setNext(current->getNext());
      //cout<<current->getPrevious()->getNext()<<endl;
      current->~node();
    }
   
    
      

  }
}
