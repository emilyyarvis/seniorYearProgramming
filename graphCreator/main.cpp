#include <iostream>
#include "vertex.h"
#include "edge.h"
#include <queue>
#include<vector>

using namespace std;


vertex* findVertex(vector<vertex*> inputList, string searchLabel,int vertexCount);
void printVertex(vector<vertex*> inputList,int vertexCount);
void buildTable(int vertexCount,vector<vertex*> vertexList,int edgeCount,vector<edge*> edgeList);
void printEdge(vector<edge*> inputList, int edgeCount);

int main(){
  
  bool loop = true;
  vector<vertex*> vertexList;
  vector<edge*> edgeList;
  int edgeCount=0;
  int vertexCount=0;
  string input;
  
  while(loop ==true){
    cout<<vertexCount<<endl;
    printEdge(edgeList,edgeCount);
    printVertex(vertexList,vertexCount);
    cin>>input;
    if(input=="ADD"){//if you want to add a vertex or edge
      cout<<"Wat would you like to add"<<endl;
      cin>>input;
      if(input=="vertex"){//adding vertex
	cout<<"What would you like to call this vertex"<<endl;
	cin>>input;
	vertex* newVertex=new vertex(input);//creates new vertex
	vertexList.push_back(newVertex);//adds to vertex list
	vertexCount++;
	
      }
      else if(input=="edge"){//adding edge
	int weight;
	string input2;
	vertex* vertex1;
	vertex* vertex2;
	cout<<"what weight do you want it to have"<<endl;
	cin>>weight;
	cout<<"point1 label?"<<endl;
	cin>>input;
	vertex1 = findVertex(vertexList,input,vertexCount);
	cout<<"point2 label>"<<endl;
	cin>>input;
	vertex2 = findVertex(vertexList,input,vertexCount);
	cout<<vertex1->getLabel()<<","<<vertex2->getLabel()<<endl;
	edge* newEdge = new edge(weight,vertex1,vertex2);//creates new edge with all input
	edgeList.push_back(newEdge);//adds edge to the edge list
	edgeCount++;

	
	
      }


    }
    else if(input=="REMOVE"){//to delete something
      cout<<"What would you like to remove"<<endl;
      cin>>input;
      if(input=="vertex"){//deleting a vertex
	int toDelete;
	cout<<"enter label for which you want to remove"<<endl;
	cin>>input;
	for(int i=0;i<vertexCount;i++){//goes through looking for the vertex to delete
	 cout<<"i: "<<i<<endl;
	 if(vertexList.at(i)->getLabel() == input){
	   toDelete= i;//finds it
	 }
       }
	vertexList.erase(vertexList.begin()+toDelete);//erase from list
       vertexCount=vertexCount-1;
      }
      else if(input=="edge"){//to delete edge
	int toDelete;
	int input3;
	cout<<"enter weight for the angle you want to remove"<<endl;
	cin>>input3;
	for(int i=0;i<edgeCount;i++){//goes through to find edge
	  cout<<"i: "<<i<<endl;
	  if(edgeList.at(i)->getWeight() == input3){
	    toDelete= i;//finds it and sets it
	  }
	}
	edgeList.erase(edgeList.begin()+toDelete);//deletes it
	edgeCount=edgeCount-1;
	
      }
    }
    else if(input=="PRINT"){
      buildTable(vertexCount,vertexList,edgeCount,edgeList);//prints the adjacency table
    }
    
    else if(input =="QUIT"){
      loop = false;
      break;
    }

   






  }

}
void printEdge(vector<edge*> inputList, int edgeCount){//prints the list of edges
  cout<<"LIST"<<endl;
  for(int i=0;i<edgeCount;i++){
    cout<<inputList.at(i)->getWeight()<<endl;
    }

}

void printVertex(vector<vertex*> inputList,int vertexCount){//prints the list of vertexs
  cout<<"LIST"<<endl;
  for(int i=0;i<vertexCount;i++){
  cout<<inputList.at(i)->getLabel()<<endl;
    }

}
                                         
                                         
vertex* findVertex(vector<vertex*> inputList, string searchLabel,int vertexCount){//finds a vertex
  for(int i=0;i<vertexCount;i++){
    if(inputList.at(i)->getLabel() == searchLabel){
      return inputList.at(i);
    }

  }
  cout<<"that vertex does not exist please enter another"<<endl;
  return NULL;
 
}


void buildTable(int vertexCount,vector<vertex*> vertexList,int edgeCount,vector<edge*> edgeList){//connection wil be based on rows

  ///////////////////////////////////////////////
  string a[vertexCount+1][vertexCount+1] ;//creates the 2d array

  for(int i=0;i<vertexCount+1;i++){//sets all tof alse
    for(int j =0;j<vertexCount+1;j++){
      a[i][j]='F';     
      
    }
  }
  a[0][0]=' ';
 
  for(int i =1; i<vertexCount+1;i++){//labels
    a[i][0]=vertexList.at(i-1)->getLabel();//row labels
    a[0][i]=vertexList.at(i-1)->getLabel();//column labels
   }
  ///////////////////////////////////////labels
  vertex* vStart;
  vertex* vEnd;
  int r=0;
  int c=0;
  for(int i=1;i<edgeCount+1;i++){
    vStart=edgeList.at(i-1)->getPoint1();
    vEnd = edgeList.at(i-1)->getPoint2();
    cout<<"THIS: "<<i-1<<endl;
    for(int i =1;i<vertexCount+1;i++){
      if(vStart == vertexList.at(i-1)){
	cout<<"start: "<<i<<endl;
	r=i;
      }
      else if(vEnd	== vertexList.at(i-1)){
	cout<<"end: "<<i<<endl;
	c=i;
      }
      // a[r][c]="T";
    }
    a[r][c]="T";//when there is a connection, T gets put in the row that the connection starts at and the c that it ends at
  }
  ////////////
  


//printing the table out
for(int i=0;i<vertexCount+1;i++){
  cout<<endl;
  for(int j =0;j<vertexCount+1;j++){
      cout<<"\t"<<a[i][j];

    }
  }
 cout<<endl;
}

