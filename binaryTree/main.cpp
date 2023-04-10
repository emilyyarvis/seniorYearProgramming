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

    }
  
    else if(input == "PRINT"){
      for(int i=0; i<position;i++){
	cout<<inputVector[i]<<endl;
      }
    }
    else if(input== "TREE"){
      printTree(inputVector,position,0,0);
    }
    else if(input == "SORT"){
      sort(inputVector,position);

    }
    else if(input=="BUILD"){
      buildTree(inputQueue, head, head);
    }
    else if(input == "QUIT"){
      loop = false;
      break;
    }
  }
}
