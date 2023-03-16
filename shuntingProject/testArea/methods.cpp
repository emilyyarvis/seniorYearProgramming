#include <iostream>
#include<stack>
#include "newNode.h"
#include "Tree.h"

using namespace std;

void checkOperator(char input[],int length,int &operatorCount){
  for(int i=0;i<length;i++){
    if(input[i] =='*'||input[i]=='-'||input[i]=='+'||input[i]=='/'||input[i]=='^'){
      operatorCount++;
    }
  }
  
}
bool checkOperatorIndividual(char input){
  if(input=='*'||input=='-'||input=='+'||input=='/'||input=='^'||input==')'||input=='('){
  return true;
}
 else{
   return false;
 }
}

bool checkOperandIndividual(char input){
  if((input!='*'&&input!='-'&&input!='+'&&input!='/'&&input!='^')&&input!=' '){
    return true;
  }
  else{
    return false;
  }
  
}
bool checkSpace(char input){
  if(input ==' '){
    return true;
  }
  else{
    return false;
  }
}

void buildStack(Node* head){


}

void buildQueue(Node* head){


}
void buildLinkedList(char input[],int length,Node* &head){
  Node* current=NULL;
  //  current = head;                                                                                                
  int LLCount=0;
  for (int i=0;i<length;i++){
    if(checkSpace(input[i])!=true){
      LLCount++;
           if(head==NULL){
        head= new Node(new Student(input[i]));
      }
      else{
        current = head;
        while(current->getNext()!=NULL){
          current = current->getNext();
        }
        current->setNext(new Node(new Student(input[i])));
      }
    }
  }
  //print                                                                                                            
  current=head;
  cout<<endl;
  for (int i=0;i<LLCount;i++){
    cout<<current->getStudent()->getValue()<<endl;
    current=current->getNext();
 }
}

void builTree(Tree* head){


}
void readInfix(char input[],int inputLength,int trueLength){
  char before;
  char temp;
  stack<char>output;
  stack<char>print;
  stack<char>operators;
  cout<<"num"<<trueLength<<endl;
  
  for(int i=0;i<inputLength;i++){
    if(checkOperatorIndividual(input[i])==true){
      if(operators.empty()==true){
	operators.push(input[i]);
      }
      else{
	char popped = ' ';
	if(input[i] == '*' || input[i] == '/'){
	  cout<<"M or D"<<endl;
	  if(operators.top() == '*' || operators.top() == '/'){
	    cout<<"1"<<endl;
	    
	     popped=operators.top();
	     output.push(popped);
	     operators.pop();
	    
	  }
	  else if(operators.top() == '+' || operators.top() == '-'){
	    cout<<"2"<<endl;
	    operators.push(input[i]);
	  }
	 }
	else if(input[i]=='+' || input[i] == '-'){
	  cout<<" A or S"<<endl;
	  if(operators.top() == '*' || operators.top() == '/'){
	    cout<<"3"<<endl;
	    popped=operators.top();
	    output.push(popped);
	    operators.pop();
	    
          }
          else if(operators.top() == '+' || operators.top() == '-'){
	    cout<<"4"<<endl;

	     popped=operators.top();
             output.push(popped);
             operators.pop();
	    
          }
	}
      }
    }
    else if(checkOperandIndividual(input[i])==true){
      cout<<"variable"<<endl;
      output.push(input[i]);
    }
    else if(checkSpace(input[i]) ==true){
      //cout<<"space"<<endl;
    }

  }
  while(!operators.empty()){
    output.push(operators.top());
    operators.pop();

  }
  print = output;
  cout<<"hello"<<endl;
  for(int i=0;i<trueLength;i++){
    cout<<print.top()<<endl;
    //cout<<"test"<<endl;
    print.pop();
  }
}
  

