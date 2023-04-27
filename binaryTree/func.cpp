#include <iostream>
#include <queue>
#include<vector>
#include "Tree.h"

using namespace std;
void sort(vector<int> &inputVector,int length){

  vector<int> sorted;

  int realLength=length;
  int largest=0;
  int count=0;
  int temp[length];
  int pos=0;
  
  
  while(count<realLength){//while we still need to go through numbers in array
    for(int i=0;i<realLength;i++){//for them all
      if(inputVector[i]>largest){//if somethings bigger then the largest found switch em
	largest=inputVector[i];
	pos=i;
      }
    }
    inputVector[pos]=0;//delte from old array
    sorted.push_back(largest);//add to new array
    largest=0;
    count=count+1;
    //sort again fro next largest until out of numbers
  }
  for(int i=0;i<realLength;i++){//reassign to array
    inputVector[i]=sorted[i];

  }
  cout<<"SORTED"<<endl;
}

void printTree(vector<int>sorted,int trueLength,int index, int level){

   if (index >= trueLength){//if there is nothing in the array passed
        return;
  }
  printTree(sorted, trueLength, 2 * index + 2, level + 1);//prints teh right side of the tree
    for (int i = 0; i < level; i++){
      cout << "   ";//prints teh correct number of spaces for the given node based on its level
    }
    cout << sorted[index] << endl;//prints the current node
    printTree(sorted, trueLength, 2 * index + 1, level + 1);//prints the left side of the tree
}
void printTree2(Tree* root,int space){

  int COUNT = 2;  

    // Base case
  if (root == NULL){
        return;
  }
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    printTree2(root->getRight(), space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++){
        cout << " ";
    }
    cout << root->getChild()->getRoot() << "\n";
 
    // Process left child
    printTree2(root->getLeft(), space);

  
}
bool searchTree(Tree* head, Tree* current, int input){
  bool check1=false;
  bool check2=false;
  
  if (current == NULL){
    return false;
  }
  if (current->getChild()->getRoot() == input){
    cout<<"This3: " <<current->getChild()->getRoot()<<endl;
    return true;
  }
 
  check1 = searchTree(head,current->getLeft(), input);

 
  if(check1){
    cout<<"This2: " <<current->getChild()->getRoot()<<endl;
    return true;
  }
 
  check2 = searchTree(head,current->getRight(), input);
  cout<<"This1: " <<current->getChild()->getRoot()<<endl;  
  return check2;

}
void deleteNode(Tree* &dNode,Tree* &head){
  Tree* temp;
  Tree* extraChild;
  Tree* newTree;
  Tree* c;
  Tree* temp2;
  int value;
  bool more = false;
  if(dNode->getRight() == NULL&& dNode->getLeft() ==NULL){
    cout<<"No children"<<endl;
    temp = dNode->getParent();
    if(temp->getRight() == dNode){
      temp->setRight(NULL);//deletes right nofde if its dnode
      dNode->setParent(NULL);//new//deletes parent of d node so there is no link
    }
    else if(temp->getLeft() == dNode){
      temp->setLeft(NULL);//deletes left node if its dnode
      dNode->setParent(NULL);//new//deletes parent of d node so there is no link
    }
    
  
  }
  //  else if(dNode == head){
  //  c = dNode->getRight();
  //  while(c->getLeft()!=NULL){
  //    c = c->getLeft();
  //  }
  //  value = c->getChild()->getRoot();
  //  head->getChild()->setRoot(value);
  //  c->getParent()->setLeft(NULL);
  // }
  
  else if(dNode->getRight()!= NULL && dNode->getLeft()!=NULL){
    cout<<"Two Children"<<endl;
    // if(dNode != head){
      c = dNode->getRight();//c is the succesor to c node 
      while(c->getLeft()!=NULL){
	c = c->getLeft();
	more = true;
      }
      if(more!=true){
	if(dNode->getParent()->getRight() == dNode){
	  c->setParent(dNode->getParent());//sets parent of the new node
	  c->setLeft(dNode->getLeft());//sets left of the new node            
	  dNode->getParent()->setRight(c);//gets the parent of the old node and sets its child as c              
	  dNode->setLeft(NULL);//new                                                                             
	  dNode->setRight(NULL);
	  dNode->setParent(NULL);
	}
	else if(dNode->getParent()->getLeft() == dNode){
	  c->setParent(dNode->getParent());//sets parent of the new node                                
	  c->setLeft(dNode->getLeft());//sets left of the new node                                               
	  dNode->getParent()->setLeft(c);//gets the parent of the old node and sets its child as c               
	  dNode->setLeft(NULL);//new                                                                             
	  dNode->setRight(NULL);
        dNode->setParent(NULL);
	}
      }
      else if(more==true){
	if(c->getRight()==NULL){//if there is not  a tree attatched to c
	  value = c->getChild()->getRoot();//gets the correct value for new node
	  c->getParent()->setLeft(NULL);//sets the parent to next null
	  dNode->getChild()->setRoot(value);//resets dnode to the correct value
	  c->setParent(NULL);//new
	  
	}
	else if(c->getRight()!=NULL){//if there is a tree attatched to c
	  value = c->getChild()->getRoot();//gets new value for new node
	  dNode->getChild()->setRoot(value);//sets the dnode to the correct value
	  temp = c->getParent();//new
	  Tree* right = c->getRight();//new
	  temp->setLeft(right);//sets the old position of c to be its right handed tree
	  right->setParent(temp);//new
	  c->setParent(NULL);//new
	  c->setRight(NULL);//new
	}
      }
      
    
  }
  else if((dNode->getRight()!= NULL && dNode->getLeft()==NULL) || (dNode->getRight()==NULL && dNode->getLeft()!=NULL)){
    cout<<"One Child"<<endl;
    //checks to see if dnode has a left or right child
    if(dNode->getRight()!=NULL){
      extraChild = dNode->getRight();
    }
    else if(dNode->getLeft()!=NULL){
      extraChild = dNode->getLeft();
    }
    temp = dNode->getParent();
    //checks to see which side of tree dnode is on
    if(temp->getRight() == dNode){
      temp->setRight(extraChild);
      extraChild->setParent(temp);//new
      dNode->setParent(NULL);//new
      dNode->setRight(NULL);//new
    }
    else if(temp->getLeft() == dNode){
      temp->setLeft(extraChild);
      extraChild->setParent(temp);//new
      dNode->setParent(NULL);//new
      dNode->setLeft(NULL);//new
    }
  }
  
  
}

Tree* findNode(Tree* node, Tree* current, int value){//gos through whole tree and searches for node given
  if(node == NULL){//returns NULL if head node doesnt exist
    return node;
  }
  if(current->getChild()->getRoot() == value){
    cout<<"found"<<endl;
    return current;
  }
  else if(current->getChild()->getRoot() <=value){
    current = current->getRight();
    return findNode(node, current,value);
  }
  else if(current->getChild()->getRoot() >value){
    current = current->getLeft();
    return findNode(node,current,value);
  }
  return findNode(node,current,value);
}


void buildTree(queue<int> &input,Tree* &head,Tree* current){
  Tree* temp;
  while(head==NULL){
    head = new Tree(new Child(input.front()));
    input.pop();
    cout<<"WHOOP: "<<head->getChild()->getRoot()<<endl;
    current = head;
  }

  if(current->getChild()->getRoot() <= (input.front())&&input.empty()!=1){
    while(current->getRight() != NULL){
      
      current = current->getRight();
      return buildTree(input,head,current);
    }
    current->setRight(new Tree(new Child(input.front())));
    temp = current->getRight();
    temp->setParent(current);
    input.pop();
    if(input.empty()==1){
     cout<<"empty"<<endl;
    }
    else{
     return buildTree(input,head,head);
      }
  }
  else if(current->getChild()->getRoot() > (input.front())&&input.empty()!=1){
    while(current->getLeft() != NULL){
      current = current->getLeft();
      return buildTree(input,head,current);
    }
    current->setLeft(new Tree(new Child(input.front())));
    temp = current->getLeft();
    temp->setParent(current);
    input.pop();
    if(input.empty()==1){
      cout<<"empty"<<endl;
    }
    else{
     return buildTree(input,head,head);
       }
    }
      cout<<"it is done"<<endl;
}

  
