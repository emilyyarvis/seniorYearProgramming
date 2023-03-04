#include <iostream>
#include <iomanip>
#include <fstream>
#include "newNode.h"
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void outputHeap(int heap[],Node* &head,int length);
int findSize(int arr[]);
void sort(int heap[],int length,int (&realHeap)[100]);

int main(){
  int inputLength=0;
  Node* head;
  bool loop=true;
  string input;
  int inputArray[100];
  for(int i=0;i<100;i++){
    inputArray[i]=-1;
  }
  int position=1;
  while(loop == true){
    cin>>input;
    if(input=="ADD"){
      cout<<"Would you like to manually input your numbers or input a file"<<endl;
      cout<<"MANUAL or FILE"<<endl;
      cin>>input;
      if(input == "FILE"){
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
	   
	    inputArray[position]=num;
	    position=position+1;
	  }
	}
	fileInput.close();
      }
      else if (input == "MANUAL"){
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
	else if(input=="RANDOM"){\
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
    else if(input =="PRINT"){
      for(int i=0;i<100;i++){
	if(inputArray[i]!=-1){
	  cout<<i<<","<<inputArray[i]<<endl;
	}
      }
    }
    else if(input=="CLEAR"){
      for(int i=0;i<100;i++){
          inputArray[i]=-1;
	}
      position = 1;
    }
    else if(input=="OUTPUT"){
      outputHeap(inputArray,head,inputLength);
    }
    else if(input=="SORT"){
      sort(inputArray,inputLength,inputArray);
    }
    else if(input=="QUIT"){
      loop=false;
    }
    else{
      cout<<"this command does not exist please try again"<<endl;
    }
    inputLength=findSize(inputArray);
   
  }


}
void sort(int heap[],int length,int (&realHeap)[100]){

  int realLength=length+1;
  int largest=0;
  int count=1;
  int temp[length];
  int pos=0;
  
  while(count<realLength){
    for(int i=1;i<realLength;i++){
      if(heap[i]>largest){
	largest=heap[i];
	pos=i;
      }
    }
    heap[pos]=0;
    temp[count]=largest;
    largest=0;
    count=count+1;
    
  }
  for(int i=1;i<realLength;i++){
    realHeap[i]=temp[i];

  }
  cout<<"SORTED"<<endl;
}

void outputHeap(int heap[],Node* &head,int length){
  int largest=0;
  int pos;
  int parent=0;
  //Node* head;
  for(int i=0;i<length;i++){
    if(i==1){
      head=new Node(new Student(heap[i]));
    }
    else if(i!=1){
      
    }
  }

  
}
int findSize(int arr[]){
  int count=0;
  for(int i=0;i<100;i++){
    if(arr[i]!=-1){
      count=count+1;
    }
  }
  return count;

}
