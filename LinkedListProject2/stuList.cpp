#include <iostream>
#include <iomanip>

#include "newNode.h"
#include <cstring>

using namespace std;

void add(int userId,Node* &firstNode,float userGPA,string firstName,string lastName,Node* current);
void print(Node* firstNode);
bool quit();
void deleter(int deletedId,Node* &head, Node* current, Node* previous);
float average(float avg,Node* &head,Node* current,int count);


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
  while(loop == true){
    cin>>userInput;
    if(userInput == "ADD"){
      cout<<"ADD"<<endl;
      cout<<"Whats the students first name"<<endl;
      cin>>inputFirst;
      cout<<"Whats the students last name"<<endl;
      cin>>inputLast;
      cout<<"Whats the students Id"<<endl;
      cin>>inputId;
      cout<<"Whats the students GPA"<<endl;
      cin>>inputGPA;
      add(inputId,head,inputGPA,inputFirst,inputLast,head);
    }
    else if(userInput == "PRINT"){
      print(head);
    }
    else if(userInput == "QUIT"){
      loop = quit();
    }
    else if(userInput == "DELETE"){
      cout<<"enter the id of the person you would like to delete"<<endl;
      cin>>inputDeleteId;
      deleter(inputDeleteId,head,head,head);
    }
    else if(userInput == "AVERAGE"){
      average(0,head,head,0);
    }
    else{
      cout<<"This command word does not exist please try again"<<endl;
    }
  }
}

void add(int userId,Node* &firstNode,float userGPA,string firstName,string lastName,Node* current){

  Node*temporaryNext;
  int newId;
  bool go=true;
  if(firstNode== NULL){//checks to see if the list is empty
    firstNode = new Node(new Student(userId,userGPA,firstName,lastName));
  }
  else if(firstNode->getStudent()->getGPA() > userGPA){//if new node is greater then head node
    temporaryNext = current;
    firstNode = new Node(new Student(userId,userGPA,firstName,lastName));
    firstNode->setNext(temporaryNext);

  }
  else{//otherwise if no special case sorts the nodes in order
    while(current->getNext()!=NULL && go==true){
      if(current->getNext()->getStudent()->getGPA() > userGPA){
	temporaryNext = current->getNext();
	current->setNext(new Node(new Student(userId,userGPA,firstName,lastName)));
	current = current->getNext();
	current->setNext(temporaryNext);
	go = false;
      }
      else{
	current = current->getNext();
       
      }
      
      }
  //if its the greatest GPA in the list put it last  
    if(go!= false){ 
      current->setNext(new Node(new Student(userId,userGPA,firstName,lastName)));
    }
  }
}

void print(Node* firstNode){//prints out all the nodes
  Node* printNode = firstNode;
  Node* temp;

  if(printNode->getNext()!=NULL){//as long as next node exists
    if(printNode->getStudent()->getId() ==0){
      printNode = printNode->getNext();
    }
    else{//print out the node information
      
      cout<<printNode->getStudent()->getFirstName()<<","<<printNode->getStudent()->getLastName()<<","<<printNode->getStudent()->getId()<<","<<setprecision(3)<<printNode->getStudent()->getGPA()<<endl;
      printNode = printNode->getNext();
      print(printNode);//recursion
    }
  }
  else{//prints the last node
    
    cout<<printNode->getStudent()->getFirstName()<<","<<printNode->getStudent()->getLastName()<<","<<printNode->getStudent()->getId()<<","<<setprecision(3)<<printNode->getStudent()->getGPA()<<endl;
  }
}


void deleter(int deletedId,Node* &head, Node* current, Node* previous){//gets a node and deletes it
  Node*foundNode;
  Node*temporaryNext;
  bool found = false;
  if(head!=NULL){
    if(head->getStudent()->getId() == deletedId){//checks the head node
      head= head->getNext();
    }
    current = previous->getNext();
    if(current->getNext() != NULL){/////////////////////////////////////////////////////////
      if(current->getStudent()->getId() == deletedId){                                    //
	temporaryNext = current->getNext();                                               //
	previous->setNext(temporaryNext);                                                 //
	current = previous->getNext();                                                    //
	found = true;                                                                     //
	                                                                                  //
      }                                                                                   //
      else{                                                                               //
	previous = previous->getNext();                                                   //
	deleter(deletedId, head, current, previous);//recursion                           //
                                                                                          //
      }                                                                                   //
    }//^goes through everything except the first and last node//////////////////////////////

    else if (current->getNext() == NULL){//checks the last
      previous->setNext(NULL);
    }
  }
}
bool quit(){//quits the game
  cout<<"Goodbye"<<endl;
  return false;
}

float average(float avg,Node* &head,Node* current,int count){//average all the GPA's in the list
  bool done = false;
    if(current->getNext()!=NULL){
      count = count+1;
      avg = avg+(current->getStudent()->getGPA());
      current = current->getNext();
      return average(avg,head,current,count);//recursion
    }
    //does the last item in the list
    count = count +1;
  avg = avg+(current->getStudent()->getGPA());
 
  avg = avg / count;
  cout<<"Average: "<<setprecision(3)<<avg<<endl;//prints to two decimals
  return avg;
}


