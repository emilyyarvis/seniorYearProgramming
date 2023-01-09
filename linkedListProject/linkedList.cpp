#include<iostream>
#include"node.h"
//#include"student.h"
using namespace std;

void add(int userId,node* &firstNode);
void print(node* firstNode);

int main(){

  student* joe = new student(1);
  node* test=new node(joe);
  node* first= NULL;
  add(22,first);
  cout<<first->getStudent()->getId()<<endl;
  print(first);
  add(15,first);
  print(first);
  add(17,first);
  print(first);
}

void add(int userId,node* &firstNode){
  node* current = firstNode;
  int newId;
  if(current== NULL){
    cout<<"i did this"<<endl;
    firstNode = new node(new student(userId));
    cout<<"yay"<<endl;
    //cout<<firstNode->getStudent()->getId()<<endl;
  }
  else{
    while(current->getNext()!=NULL){
      current = current->getNext();
    }
    current->setNext(new node(new student(userId)));
    
  }
}

void print(node* firstNode){
  node* printNode = firstNode;
  cout<<endl;
  while(printNode->getNext()!=NULL){
    cout<<printNode->getStudent()->getId()<<endl;
    printNode = printNode->getNext();
  }
  cout<<printNode->getStudent()->getId()<<endl;

}
