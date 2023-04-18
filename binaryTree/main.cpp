#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<queue>
#include "func.cpp"

using namespace std;

int main(){
  Tree* head = NULL;
  bool loop = true;
  vector<int> inputVector;
  queue<int> inputQueue;
  int position = 0;
  string input;
  //take in from the user random and file
  //sort
  //print to a tree
  //resort with deletes and adds
  while(loop == true){
cin>>input;
    if(input=="ADD"){//add to heap
      cout<<"Would you like to manually input your numbers or input a file"<<endl;
      cout<<"MANUAL or FILE"<<endl;
      cin>>input;
      if(input == "FILE"){//file additions
	cout<<"What is the name of your file? do NOT include .txt in your answer"<<endl;
	cin>>input;
	input=input+".txt";
       	ifstream fileInput;	
	fileInput.open(input);
	
	if(!fileInput.is_open()){
	  cout<<"NO"<<endl;
	}
   
	while(fileInput){
	  string line;  
	  getline(fileInput,line,' ');
	  
	  if(line !="\0"&&line!=" "){
	    int num = stoi(line);
	   
	    inputVector.push_back(num);//adds everything from file to array
	    inputQueue.push(num);
	    position=position+1;
	  }
	}
	fileInput.close();
      }
      else if(input == "MANUAL"){
	int input2;
	cout<<"Which number owuld you like to add?"<<endl;
	cin>>input2;
	inputVector.push_back(input2);
	inputQueue.push(input2);
	position = position+1;

      }
    }
  
    
    else if(input == "DELETE"){
      //case 1 is when it is just a leaf and doesnt have any children attatched to it
      //case 2 is node to be deleted only has one child
      //case 3 is node to be deleted has 2 children
      int value;
      cout<<"What number would you like to delete"<<endl;
      cin>>value;
      Tree* test =  findNode(head,head,value);
      cout<<test->getChild()->getRoot()<<endl;
      deleteNode(test,head);
      
    }
    else if(input == "SEARCH"){
      int inputNew;
      cout<<"What number would you like to look for"<<endl;
      cin>>inputNew;
      bool input = searchTree(head,head,inputNew);
      if(input == true){
	cout<<"That value is in the Tree!"<<endl;
      }
      else if(input == false){
	cout<<"That value is not in the Tree!"<<endl;
      }
    }
    else if(input== "TREE"){
      printTree(inputVector,position,0,0);
    }
    else if(input == "SORT"){
      sort(inputVector,position);

    }
    else if(input=="PRINT"){
      
      buildTree(inputQueue, head, head);
      for(int i=0; i<position;i++){
        inputVector.pop_back();
       }
      position = 0;
      
      printTree2(head,0);
    }
    else if(input == "QUIT"){
      loop = false;
      break;
    }
  }
}
