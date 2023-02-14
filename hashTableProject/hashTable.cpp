#include <iostream>
#include <iomanip>

#include "newNode.h"
#include <cstring>

using namespace std;

void hashFunction(int userId,float userGPA,string firstName,string lastName,int bucketSize, Node* hash[]);
void hashPrint(Node* hash[],int bucketSize);
bool quit();
void hashDelete(int deletedId,Node* hash[],int bucketSize);


int main(){
  bool loop = true;
  string input;
  Node* head=NULL;

  string userInput;
  string inputFirst;
  string inputLast;
  int inputId=0;
  int inputDeleteId=0;
  float inputGPA=0;


  //hash stuff
  int bucketSize=100;
  Node* hash[bucketSize];
  //intializes hash
  for(int i=0;i<bucketSize;i++){
    hash[i] = NULL;
  }
  /////////////////////////////////////////////////////////
  while(loop == true){
    cin>>userInput;
    if(userInput == "ADD"){
      cout<<"Whats the students first name"<<endl;
      cin>>inputFirst;
      cout<<"Whats the students last name"<<endl;
      cin>>inputLast;
      cout<<"Whats the students Id"<<endl;
      cin>>inputId;
      cout<<"Whats the students GPA"<<endl;
      cin>>inputGPA;
      hashFunction(inputId,inputGPA,inputFirst,inputLast,bucketSize,hash);
      
    }
    else if(userInput == "PRINT"){
      hashPrint(hash,bucketSize);
    }
    else if(userInput == "QUIT"){
      loop = quit();
    }
    else if(userInput == "DELETE"){
      cout<<"enter the id of the person you would like to delete"<<endl;
      cin>>inputDeleteId;
      hashDelete(inputDeleteId,hash,bucketSize);
    }
    else{
      cout<<"This command word does not exist please try again"<<endl;
    }
  }
}


void hashFunction(int userId,float userGPA,string firstName,string lastName,int bucketSize, Node* hash[]){
  int value=0;
  Node* head = NULL;
  Node* current= NULL;
  value = userId % bucketSize;
  cout<<value<<endl;
  if(hash[value] == NULL){
    hash[value] = new Node(new Student(userId,userGPA,firstName,lastName));
    //hash[value]->setStudent(newStudent);
    cout<<hash[value]->getStudent()->getId()<<endl;
    cout<<"hello"<<endl;
  }
  else{
    head = hash[value];
    current = hash[value];
    while(current->getNext()!=NULL){
      current = current->getNext();
    }

    current->setNext(new Node(new Student(userId,userGPA,firstName,lastName)));
    current = current->getNext();
    cout<<current->getStudent()->getFirstName()<<endl;
    
    cout<<"hullo"<<endl;
  }

}


void hashPrint(Node* hash[],int bucketSize){
  int count = 0;
  Node* current= NULL;
  for(int i=0;i<bucketSize;i++){
    if(hash[i]==NULL){
      cout<<i<<", "<<"Nice"<<endl;
    }
    else{
      current = hash[i];
      
      while(current->getNext()!=NULL){
	cout<<i<<", "<<current->getStudent()->getFirstName()<<endl;
	current = current->getNext();
      }
      cout<<i<<", "<<current->getStudent()->getFirstName()<<endl;
    }
  }

}
void hashDelete(int deletedId,Node* hash[],int bucketSize){

  int value = 0;
  value = deletedId % bucketSize;
  if(hash[value] == NULL){
    cout<<"This value does not exist"<<endl; 
    }
  else{
    if(hash[value]->getNext() == NULL){
      hash[value] = NULL;
    }
    else{
      hash[value] = hash[value]->getNext();
    }
  }

}

bool quit(){//quits the game
  cout<<"Goodbye"<<endl;
  return false;
}













 