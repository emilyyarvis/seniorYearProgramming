#include <iostream>
#include <iomanip>
#include <fstream>
#include "newNode.h"
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void outputHeap(int heap[],Node* &head,int length);
int findSize(int arr[]);
void sort(int heap[],int length,int (&newHeap)[100]);
void printMaxHeap(int heap[], int trueLength, int index, int level);

int main(){
  int inputLength=0;
  Node* head;
  bool loop=true;
  string input;
  int inputArray[100];
  for(int i=0;i<100;i++){
    inputArray[i]=-1;
  }
  int position=0;

  cout<<"say ADD to add values, output to print to command line in tree, CLEAR to clear items, and QUIT to quit program"<<endl;
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
	   
	    inputArray[position]=num;//adds everything from file to array
	    position=position+1;
	  }
	}
	fileInput.close();
      }
      else if (input == "MANUAL"){//manual additions
	cout<<"RANDOM or MANUAL"<<endl;
	cin>>input;
	if(input=="MANUAL"){
	  int inputCount=0;
	  int nextValue=0;
	  cout<<"How many numbers would you like to add"<<endl;
	  cin>>inputCount;
	  for(int i=0;i<inputCount;i++){
	    cout<<"input your "<<i<<"th number"<<endl;
	    cin>>nextValue;
	    inputArray[position]=nextValue;
	    position=position+1;
	    
	  }
	}
	else if(input=="RANDOM"){//adds random numbers
	  int newValues;
	  cout<<"How many values would you like to randomly add"<<endl;
	  int random;
	  cin>>newValues;
	  srand(time(NULL));
	  for(int i=0;i<newValues;i++){
	  random=rand()%100;
	  inputArray[position]=random;
	  position=position+1;
	  cout<<random<<endl;
	  }
	  
	}
      }
    }
    else if(input =="PRINT"){//prints all numbers in heap
      for(int i=0;i<100;i++){
	if(inputArray[i]!=-1){
	  cout<<i<<","<<inputArray[i]<<endl;
	}
      }
    }
    else if(input=="CLEAR"){//deletes all numbers from heap
      for(int i=0;i<100;i++){
          inputArray[i]=-1;
	}
      position = 0;
    }
    else if(input=="OUTPUT"){//outputs numbers to the tree in command line
      
      sort(inputArray,inputLength,inputArray);
      int trueLength = sizeof(inputArray) / sizeof(inputArray[0]);
      printMaxHeap(inputArray, trueLength, 0, 0);
    }
    else if(input=="SORT"){//puts heap in order
      sort(inputArray,inputLength,inputArray);
    }
    else if(input=="QUIT"){//quits program
      loop=false;
    }
    else{
      cout<<"this command does not exist please try again"<<endl;
    }
    inputLength=findSize(inputArray);//resizes the length based on input
   
  }


}
void sort(int heap[],int length,int (&newHeap)[100]){//sorts the array big to smal

  int realLength=length;
  int largest=0;
  int count=0;
  int temp[length];
  int pos=0;
  
  
  while(count<realLength){//while we still need to go through numbers in array
    for(int i=0;i<realLength;i++){//for them all
      if(heap[i]>largest){//if somethings bigger then the largest found switch em
	largest=heap[i];
	pos=i;
      }
    }
    heap[pos]=0;//delte from old array
    temp[count]=largest;//add to new array
    largest=0;
    count=count+1;
    //sort again fro next largest until out of numbers
  }
  for(int i=0;i<realLength;i++){//reassign to array
    newHeap[i]=temp[i];

  }
  cout<<"SORTED"<<endl;
  
}


///

void printMaxHeap(int heap[], int trueLength, int index, int level) {
  if (index >= trueLength){//if there is nothing in the array passed
        return;
  }
  printMaxHeap(heap, trueLength, 2 * index + 2, level + 1);//prints teh right side of the tree
    for (int i = 0; i < level; i++){
      cout << " ";//prints teh correct number of spaces for the given node based on its level
    }
    cout << heap[index] << endl;//prints the current node
    printMaxHeap(heap, trueLength, 2 * index + 1, level + 1);//prints the left side of the tree
}

///


int findSize(int arr[]){//finds the true size of the array/the number of entered elements
  int count=0;
  for(int i=0;i<100;i++){
    if(arr[i]!=-1){
      count=count+1;
    }
  }
  return count;

}
