#include <iostream>
#include <stack>
//#include "newNode.h"
#include "methods.cpp"

using namespace std;

//void checkOperator(char input[],int length,int &operatorCount);
//bool checkOperandIndividual(int index, char input[]);
//bool checkOperatorIndividual(int index, char input[]);
//void buildLinkedList(char input[],int length,Node* &head);
//bool checkSpace(int index,char input[]);

int main(){
 //initializes variables
  int n = 80;//max charecters that can be checked
  char initialStr[n];
  int count = 0;
  int length = 0;
  int trueLength = 0;
  int track =0;
  int operatorCount=0;
  Node* LLHead=NULL;
  //
  
  
  //gets the input from the user
  //  test();
  cout << "type in a word"<<endl;
  cin.get(initialStr,n);//calls initialStr this inputted value
  cin.get();
  
  int spaceCount=0;
   for(int i =0; i<n; i++){
     if(initialStr[i] == ' '){
       spaceCount++;
     }
     if(initialStr[i] == '\0'){//finds the real length of the char string
       //cout<<"found"<<endl;
       length = i;//sets it as length
       break;
     } 
    }
   trueLength = (length-spaceCount);
   readInfix(initialStr,length,trueLength);
   //buildLinkedList(initialStr,length,LLHead);
}
