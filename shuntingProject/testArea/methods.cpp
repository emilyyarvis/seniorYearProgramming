#include <iostream>
#include<stack>
#include "newNode.h"
#include "Tree.h"
#include <queue>
using namespace std;

void inFix(Tree* head);
void postFix(Tree* head);
void preFix(Tree* head);
void createTree(queue<char> inputQueue);

void checkOperator(char input[],int length,int &operatorCount){//gets operator count of entire array
  for(int i=0;i<length;i++){
    if(input[i] =='*'||input[i]=='-'||input[i]=='+'||input[i]=='/'||input[i]=='^'){
      operatorCount++;
    }
  }
  
}
bool checkOperatorIndividual(char input){//checks pos in array for operator
  if(input=='*'||input=='-'||input=='+'||input=='/'||input=='^'||input==')'||input=='('){
  return true;
}
 else{
   return false;
 }
}

bool checkOperandIndividual(char input){//checks pos in array for operand
  if((input!='*'&&input!='-'&&input!='+'&&input!='/'&&input!='^')&&input!=' '){
    return true;
  }
  else{
    return false;
  }
  
}
bool checkSpace(char input){//checks pos in array for space
  if(input ==' '){
    return true;
  }
  else{
    return false;
  }
}

void buildLinkedList(char input[],int length,Node* &head){//builds linked list from infix notation
  Node* current=NULL;
  //  current = head;                                                                                                
  int LLCount=0;
  for (int i=0;i<length;i++){
    if(checkSpace(input[i])!=true){//adds to list if not a space
      LLCount++;
      if(head==NULL){//if no head make one
        head= new Node(new Student(input[i]));
      }
      else{//if head does exist go to end of list and add it there
        current = head;
        while(current->getNext()!=NULL){
          current = current->getNext();
        }
        current->setNext(new Node(new Student(input[i])));
      }
    }
  }
  //prints list to debug                                                                                                            
  current=head;
  cout<<endl;
  for (int i=0;i<LLCount;i++){
    cout<<current->getStudent()->getValue()<<endl;
    current=current->getNext();
 }
}

void readInfix(char input[],int inputLength,int trueLength){//reads the infix
  char before;
  char temp;
  queue<char>output;
  queue<char>print;
  stack<char>operators;
  cout<<"num"<<trueLength<<endl;
  
  for(int i=0;i<inputLength;i++){
    if(checkOperatorIndividual(input[i])==true){//if operator
      if(operators.empty()==true){//if empty push into operator stack
	operators.push(input[i]);
      }
      else{//if not empty
	char popped = ' ';
	if(input[i] == '*' || input[i] == '/'){//if input is M or D 
	  if(operators.top() == '*' || operators.top() == '/'){//and top of stack is M or D then 
	    popped=operators.top();//push operator off stack and into outputqueue and put new operator into stack
	     output.push(popped);
	     operators.pop();
	     operators.push(input[i]);
	    
	  }
	  else if(operators.top() == '+' || operators.top() == '-'){//if top stack is A or S push on top of stack
	    operators.push(input[i]);
	  }
	 }
	else if(input[i]=='+' || input[i] == '-'){//if input is A or S
	  if(operators.top() == '*' || operators.top() == '/'){//if top of operator is M or D
	    popped=operators.top();//push top operator out and onto output queue and push input on stack
	    output.push(popped);
	    operators.pop();
	    operators.push(input[i]);
          }
          else if(operators.top() == '+' || operators.top()=='-'){//if input is A or S
	    popped=operators.top();//push top operator onto output queue and push input onto stack
             output.push(popped);
             operators.pop();
	     operators.push(input[i]);
          }
	}
      }
    }
    else if(checkOperandIndividual(input[i])==true){//if input is operand push onto output stack
      cout<<"variable"<<endl;
      output.push(input[i]);
    }
    else if(checkSpace(input[i]) ==true){//if its  space do nothing
      //cout<<"space"<<endl;
    }

  }
  while(operators.empty()!=true){//at the end push the remaining operators off the stack
    output.push(operators.top());
    operators.pop();

  }
  // print = output;
  // cout<<"hello"<<endl;
  // for(int i=0;i<trueLength;i++){
  //  cout<<print.front()<<endl;
    //cout<<"test"<<endl;
  //   print.pop();
  // }

  createTree(output);

}


void createTree(queue<char> inputQueue){//makes the binary tree from the output queue
  queue<Tree*> sort;
  queue<Tree*> print;
 
  
  while(!inputQueue.empty()){
    if(checkOperandIndividual(inputQueue.front())==true){//if its an operand push it into the queue
      Tree* t = new Tree(new Child(inputQueue.front()));//make it a tree 
      sort.push(t);//push it into the queue
      inputQueue.pop();//remove from input
    }
    else if(checkOperatorIndividual(inputQueue.front())==true){//if its an operator give it L and R tree + queue
      Tree* t =	new Tree(new Child(inputQueue.front()));//make into tree
      inputQueue.pop();//remove from input

      while(!sort.empty()){
	if(t->getLeft()==NULL){//give it left node
	  t->setLeft(sort.front());
	  sort.pop();
	}
	else if(t->getRight()==NULL){//give it right node
	  t->setRight(sort.front());
	  sort.pop();
	}

      }
      sort.push(t);//push it into the queue
    }
    
  }
  // print=sort;

  string input;
  cout<<"Do you want to print PREFIX, INFIX, or POSTFIX"<<endl;
  cin>>input;
  if(input=="PREFIX"){//prints prefix
    preFix(sort.front());
  }
  else if(input=="POSTFIX"){//print postfix
    postFix(sort.front());
  }
  else if(input=="INFIX"){//prints infix
    inFix(sort.front());
  }

  
 
}
void postFix(Tree* head){//recursivley prints postfix notation from binary tree 
  
  if(head->getLeft()!=NULL){
    postFix(head->getLeft());

  }
  if(head->getRight()!=NULL){
    postFix(head->getRight());
  }

  cout<<head->getChild()->getRoot()<<endl;


}

void preFix(Tree* head){//recursivley prints prefix notation from binary tree 
  cout<<head->getChild()->getRoot()<<endl;
  if(head->getLeft()!=NULL){
    preFix(head->getLeft());

  }
  if(head->getRight()!=NULL){
    preFix(head->getRight());
  }
}
void inFix(Tree* head){//recursivley prints infix notation from binary tree
 
  if(head->getLeft()!=NULL){
    inFix(head->getLeft());
  }
  cout<<head->getChild()->getRoot()<<endl;
  if(head->getRight()!=NULL){
    inFix(head->getRight());
  }
}
