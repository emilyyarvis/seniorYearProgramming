#include <iostream>
#include <queue>
#include<vector>
#include "Tree.h"

using namespace std;

void recolor(Tree* &input);
void recursiveCheck(Tree* &head,Tree* current);
void caseFive(Tree* &head,Tree*current);
void correctCheck(Tree* head, Tree* current, bool &finish);


bool done =false;
bool fin = false;

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
    inputVector[pos]=0;//delete from old array
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
    for (int i = COUNT; i < space-1; i++){
      cout << " ";
          }
    // cout<<"-";
    cout<<endl;
    
    for (int i = COUNT; i < space; i++){
        cout << " ";
    
    }
    
    
    cout <<root->getChild()->getRoot()<<root->getChild()->getColor()<<"\n";
 
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
  else if(dNode == head){
   c = dNode->getRight();
   while(c->getLeft()!=NULL){
     c = c->getLeft();
     more = true;
   }

   if (more!=true){
     head->getChild()->setRoot(c->getChild()->getRoot());
     head->setRight(c->getRight());
     head->getRight()->setParent(head);
     c->setRight(NULL);
     c->setParent(NULL);

   }
   else if (more == true){
     if(c->getRight()!=NULL){
     head->getChild()->setRoot(c->getChild()->getRoot());
     extraChild = c->getRight();
     c->getParent()->setLeft(extraChild);
     extraChild->setParent(c->getParent());
     c->setParent(NULL);
     c->setRight(NULL);
       }
     else if(c->getRight()==NULL){
       head->getChild()->setRoot(c->getChild()->getRoot());
       c->getParent()->setLeft(NULL);
       c->setParent(NULL);
     }
   }
  //  value = c->getChild()->getRoot();
  //  head->getChild()->setRoot(value);
  //  c->getParent()->setLeft(NULL);
  }
  
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

/*
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
    check(head,current);//new
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
    check(head,current);//new
    if(input.empty()==1){
      cout<<"empty"<<endl;
    }
    else{
     return buildTree(input,head,head);
       }
    }
      cout<<"it is done"<<endl;
}
*/
///////////////////////////////////////////////////////////////////////////
void buildTree2(queue<int> &input,Tree* &head,Tree* current){
  Tree* temp;
  while(head == NULL){//case 1 no head node

    head = new Tree(new Child(input.front()));
    head->getChild()->setColor('B');
    input.pop();
    cout<<"WHOOP: "<<head->getChild()->getRoot()<<endl;
    current = head;
  }
  if(current->getChild()->getRoot() <= (input.front())&&input.empty()!=1){
    while(current->getRight() != NULL){
      current = current->getRight();
      return buildTree2(input,head,current);
    }
   
      cout<<"black"<<endl;
      current->setRight(new Tree(new Child(input.front())));
      temp = current->getRight();
      temp->setParent(current);
      input.pop();
      cout<<current->getChild()->getRoot()<<endl;
      correctCheck(head,current->getRight(),fin);
      if(input.empty()==1){
	cout<<"empty"<<endl;
      }
      else{
	return buildTree2(input,head,head);
      } 
   

  }
  else if(current->getChild()->getRoot() > (input.front())&&input.empty()!=1){
    
    while(current->getLeft() != NULL){
      current = current->getLeft();
      return buildTree2(input,head,current);
    }
   
   
      current->setLeft(new Tree(new Child(input.front())));
      temp = current->getLeft();
      temp->setParent(current);
      input.pop();
      cout<<current->getChild()->getRoot()<<endl;
      correctCheck(head,current->getLeft(),fin);
      
      if(input.empty()==1){
        cout<<"empty"<<endl;
      }
      else{
        return buildTree2(input,head,head);
      }
   
    
    
  }
  
}


void caseOne(Tree* &head,Tree* current,bool &finish){//case 1               
  if(head->getChild()->getColor()!= 'B'){
    cout<<"Case One"<<endl;
    head->getChild()->setColor('B');
    finish=true;
  }
}

void caseTwo(Tree* &head, Tree* current,bool &finish){
  if(current->getParent()->getChild()->getColor()=='B'){
    finish = true;
  }

}

void caseRedChildren(Tree* &head,Tree* current){
  cout<<"yoo: "<<current->getChild()->getRoot()<<endl;
  cout<<"I am here"<<endl;
  if(current->getParent()!=NULL&&current->getParent()->getChild()->getColor() == 'R'){
    recolor(current);
  }
  

  //  printTree2(head,0);
  
}
void caseThree(Tree* &head,Tree* current, bool &finish){

  if(current!=head && current->getParent()!=NULL && current->getParent()->getParent()!=NULL && current->getParent()->getChild()->getColor() == 'R'){
   
      Tree* p = current->getParent();
      Tree* g =current->getParent()->getParent();
      Tree* u = NULL;
      if(p->getRight() == current){
	if(g->getRight() == p){
	  if(g->getLeft()!=NULL){
	    u = g->getLeft();
	  }
	 
	  
	}
	else if(g->getLeft() ==p){
	  if(g->getRight()!=NULL){
	    u = g->getRight();
	  }
	 

	}
      }
      
      else  if(p->getLeft() == current){
	if(g->getRight() == p){
	  if(g->getLeft()!=NULL){
	    u = g->getLeft();
	  }
	}
        else if(g->getLeft()==p ){
	  if(g->getRight()!=NULL){
	    u = g->getRight();
	  }
	}
      }
      if(u!=NULL&& u->getChild()->getColor() == 'R'){
	cout<<"Case3"<<endl;
	recolor(p);
	recolor(g);
	recolor(u);
	correctCheck(head,g,finish);

      }
  
  
  }





}
  

/*

void caseThree(Tree* &head,Tree* current,bool &finish){
 
  cout<<current->getChild()->getRoot()<<endl;
 
  if(current!=head){
    if(current->getParent()!=NULL&&current->getParent()->getChild()->getColor() == 'R'){//case 3 parent and uncle are red                          
      // cout<<"Case 3"<<endl;
    if(current->getParent()->getRight() == current){//means current is on the right                                       
      if(current->getParent()->getParent()->getLeft()!=NULL&&current->getParent()->getParent()->getLeft()->getChild()->getColor() == 'R'){
	cout<<"Case3R"<<endl;
	Tree* p = current->getParent();
        Tree* g = current->getParent()->getParent();
        Tree* u = current->getParent()->getParent()->getLeft();
        recolor(p);
        recolor(g);
        recolor(u);
	correctCheck(head,g,finish);	
      }
     
    }
    else if (current->getParent()->getLeft() == current){//means current is on the left                                   
      if(current->getParent()->getParent()->getRight()!=NULL && current->getParent()->getParent()->getRight()->getChild()->getColor() == 'R'){
	cout<<"case 3L"<<endl;
	Tree* p = current->getParent();
        Tree* g = current->getParent()->getParent();
	Tree* u = current->getParent()->getParent()->getRight();
        recolor(p);
        recolor(g);
        recolor(u);
	
	correctCheck(head,g,finish);
	
      }

    }
    
  }
  else if(current->getParent()->getChild()->getColor() == 'B'){
    cout<<"nope"<<endl;
    
  }
  }
 
 

 }
*/
void caseFour(Tree* &head, Tree* current,bool &finish){
  if(current!= NULL && current->getParent()!=NULL&&current->getParent()->getParent()!=NULL){//as long as node and par and grandparent doesnt equal null
    Tree* p=current->getParent();
    Tree* g=current->getParent()->getParent();
    // Tree* u=NULL;
    Tree* a=NULL;
    bool aCheck=false;
    Tree* b=NULL;
    bool bCheck=false;
    Tree* c=NULL;
    bool cCheck=false;
    if(p->getChild()->getColor() == 'R' && current->getChild()->getColor() == 'R'){//check to make sure current and parent are red
      if(g->getLeft() == p && p->getRight() == current){//left case 4
	if((g->getRight() !=NULL && g->getRight()->getChild()->getColor()== 'B')||g->getRight() == NULL){//uncle exists and is black or is null

	  cout<<"Case4R"<<endl;

	  //add extra children
	  if(p->getLeft()!=NULL){
	    a = p->getLeft();
	    aCheck = true;
	  }
	  if(current->getLeft()!=NULL){
	    b = current->getLeft();
	    bCheck = true;
	  }
	  if(current->getRight()!=NULL){
	    c = current->getRight();
	    cCheck = true;
	  }

	  g->setLeft(current);
	  current->setParent(g);
	  current->setLeft(p);
	  p->setParent(current);
	  p->setLeft(NULL);
	  p->setRight(NULL);
	  current->setRight(NULL);
	  
	  //add extra children back in
	  if(aCheck ==true){
	    p->setLeft(a);
	  }
	  if(bCheck == true){
	    p->setRight(b);
	  }
	  if(cCheck == true){
	    current->setRight(c);
	  }
	  finish=true;//new
	  caseFive(head,p);
	  //CALL CASE5 ON THE PAREMT 

	}


	
      }
      else if(g->getRight() == p && p->getLeft() == current){//right case 4
	cout<<"atleast this happend"<<endl;
	if((g->getLeft()!=NULL && g->getLeft()->getChild()->getColor()== 'B')||g->getLeft()==NULL){//uncle exists and is black or null
	  cout<<"case4L"<<endl;
	  if(current->getLeft()!=NULL){
            a = current->getLeft();
            aCheck = true;
          }
          if(current->getRight()!=NULL){
            b = current->getRight();
            bCheck = true;
          }
          if(p->getRight()!=NULL){
            c = p->getRight();
            cCheck = true;
          }

	  g->setRight(current);
	  current->setParent(g);
	  current->setRight(p);
	  p->setParent(current);
	  current->setLeft(NULL);
	  p->setLeft(NULL);
	  p->setRight(NULL);

	  if(aCheck == true){
	    current->setLeft(a);
	  }
	  if(bCheck == true){
	    p->setLeft(b);
	  }
	  if(cCheck == true){
	    p->setRight(c);
	  }
	  finish=true;//new
	 caseFive(head,p); 
	}

      }










    }

    
    
  
  }
}


/*
void caseFour(Tree* &head, Tree* current){
  if(current->getParent()!=NULL && current->getParent()->getParent()!= NULL){
    Tree* p = current->getParent();
    Tree* g = current->getParent()->getParent();
    Tree* u = NULL;
    Tree* a = NULL;//extra children
    Tree* b = NULL;//extra children
    Tree* c = NULL;//extra children
    if(current!=NULL && p!=NULL && g!=NULL&&current!=head && p->getChild()->getColor()=='R' &&current->getChild()->getColor() == 'R'){
      
      if(g->getLeft() == p){//checks to see which side the uncle should be for the given case
	if(g->getRight() != NULL){
	  u = g->getRight();
	  
	  if(p->getRight() == current &&u!=NULL&& u->getChild()->getColor()=='B'){//checks to make sure that parent and current are on the irght side of eachother
	    cout<<"Case 4 Right"<<endl;
	    
	    //temp store children
	    if(p->getLeft()!=NULL){
	      a = p->getLeft();
	    }
	    if(current->getLeft() !=NULL){
	      b = current->getLeft();
	    }
	    if(current->getRight()!=NULL){
	      c = current->getRight();
	    }
	    cout<<"1"<<endl;
	    
	    //current
	    g->setLeft(current);
	    current->setParent(g);
	    current->setRight(NULL);
	    current->setLeft(NULL);
	    //parent          g->setLeft(current);
	    current->setParent();//ALERTTTTT
          current->setLeft(p);
          p->setParent(current);
          p->setLeft(NULL);
          p->setRight(NULL);
          current->setRight(NULL);//ALERTTT
	    current->setLeft(p);
	    p->setParent(current);
	    p->setLeft(NULL);
	    p->setRight(NULL);
	    //setting a b and c
	    p->setLeft(a);
	    a->setParent(p);
	    p->setRight(b);
	    b->setParent(p);
	    current->setRight(c);
	    c->setParent(current);
	    caseFive(head,p,done);
	  }
	}
	else if(g->getRight()==NULL){
	  u = NULL;
	  
	  if(p->getRight() == current){//checks to make sure that parent and current are on the irght side of eachother                     
	    cout<<"Case 4 Right"<<endl;
	    
	    //temp store children                                                                                                                                                      
	    if(p->getLeft()!=NULL){
	      a = p->getLeft();
	    }
	    if(current->getLeft() !=NULL){
	      b = current->getLeft();
	    }
	    if(current->getRight()!=NULL){
	      c = current->getRight();
	    }
	    
	    
	    //current                                                                                                                                                                  
	    g->setLeft(current);
	    current->setParent(g);
	    current->setRight(NULL);
	    current->setLeft(NULL);
	    //parent                                                                                                                                                                   
	    current->setLeft(p);
	    p->setParent(current);
	    p->setLeft(NULL);
	    p->setRight(NULL);
	    //setting a b and c                                                                                                                                                        
	    p->setLeft(a);
	    a->setParent(p);
	    p->setRight(b);
	    b->setParent(p);
	    current->setRight(c);
	    c->setParent(current);
	    caseFive(head,p,done);
	  }
	  
	}
      }
      else if(g->getRight() == p){
	if(g->getLeft()!=NULL){
	  u =  g->getLeft();
	  cout<<"WHAT THE FFINF HELL"<<endl;
	  
	  
	  if(p->getLeft() == current && u->getChild()->getColor()=='B'){
	    cout<<"Case 4 left"<<endl;
	    
	    
	    if(current->getLeft() != NULL){
	      a = current->getLeft();
	    }
	    if(current->getRight()!=NULL){
	      b = current->getRight();
	    }
	    if(p->getRight()!=NULL){
	      c = p->getRight();
	    }
	    //current
	    g->setRight(current);
	    current->setParent(g);
	    current->setRight(NULL);
	    current->setLeft(NULL);
	    //parent
	    current->setRight(p);
	    p->setParent(current);
	    p->setLeft(NULL);
	    p->setRight(NULL);
	    //adding in extra children
	    p->setRight(c);
	    c->setParent(p);
	    p->setLeft(b);
	    b->setParent(p);
	    current->setLeft(a);
	    a->setParent(current);
	    caseFive(head,p,done);
	    
	  }
	}
	if(g->getLeft()==NULL){
	  u =  NULL;
	  cout<<"WHAT THE FFINF HELL"<<endl;
	  
	  
	  if(p->getLeft() == current ){
	    cout<<"Case 4 left"<<endl;
	    
	    
	    if(current->getLeft() != NULL){
	      a = current->getLeft();
	    }
	    if(current->getRight()!=NULL){
	      b = current->getRight();
	    }
	    if(p->getRight()!=NULL){
	      c = p->getRight();
	    }
	    //current                                                                                                                                                                  
	    g->setRight(current);
	    current->setParent(g);
	    current->setRight(NULL);
	    current->setLeft(NULL);
	    //parent                                                                                                                                                                   
	    current->setRight(p);
	    p->setParent(current);
	    p->setLeft(NULL);
	    p->setRight(NULL);
	    //adding in extra children                                                                                                                                                 
	    p->setRight(c);
	    c->setParent(p);
	    p->setLeft(b);
	    b->setParent(p);
	    current->setLeft(a);
	    a->setParent(current);
	    caseFive(head,p,done);
	    
	  }
	  
	  
	  
	  
	  
	  
	  
	  
	  
	}
      }
    }
  }
}

*/

void caseFive(Tree* &head,Tree* current){//uncle is black and parent and current are bith to the irght or left
  if(current!=NULL&&current->getParent()!=NULL&&current->getParent()->getParent()){//if current and parent and g are not null
    Tree* p = current->getParent();
    Tree* g = current->getParent()->getParent();
    Tree* u = NULL;
    Tree* a = NULL;
    bool aCheck=false;
    Tree* b = NULL;
    bool bCheck = false;
    Tree* c = NULL;
    bool cCheck = false;
    Tree* d = NULL;
    bool dCheck = false;
    Tree* e =NULL;
    bool eCheck = false;
    if(g->getLeft() == p && p->getLeft()==current&& p->getChild()->getColor() == 'R' && current->getChild()->getColor() == 'R'){

      //if uncle is not NULL but black
      if(g->getRight()!=NULL && g->getRight()->getChild()->getColor() == 'B'){
	cout<<"CASE5L UNCLE"<<endl;
	u = g->getRight();
	//assign children
	if(current->getLeft()!=NULL){
	  a = current->getLeft();
	  aCheck=true;
	}
	if(current->getRight()!=NULL){
	  b = current->getRight();
          bCheck=true;
	}
	if(p->getRight()!=NULL){
	  c = p->getRight();
          cCheck=true;
	}
	if(u->getLeft()!=NULL){
	  d = u->getLeft();
          dCheck=true;
	}
	if(u->getRight()!=NULL){
	  e = u->getRight();
          eCheck=true;
	}
	//////////////////////////////////////////
	if(g ==head){
	  head = p;
	  p->setParent(NULL);
	}
	else if(g!=head){//////////
	  Tree* gp;
	  gp = g->getParent();
	  if(gp->getLeft()==g){
	    gp->setLeft(p);
	    p->setParent(gp);
	  }
	  else if(gp->getRight()==g){
	    gp->setRight(p);
	    p->setParent(gp);
	  }
	}///////////dealing woth head null or not

	//p->setParent(NULL);
	p->setLeft(current);
	current->setParent(p);
	p->setRight(g);
	g->setParent(p);
	g->setRight(u);
	u->setParent(g);
	
	current->setLeft(NULL);
	current->setRight(NULL);
	g->setLeft(NULL);
	u->setRight(NULL);
	u->setLeft(NULL);


	if(aCheck==true){
	  current->setLeft(a);
	  a->setParent(current);
	}
	if(bCheck==true){
	  current->setRight(b);
	  b->setParent(current);
        }
	if(cCheck==true){
	  g->setLeft(c);
	  c->setParent(g);
        }
	if(dCheck==true){
	  u->setLeft(d);
	  d->setParent(u);
        }
	if(eCheck==true){
	  u->setRight(e);
	  e->setParent(u);
        }
	
	recolor(p);
	recolor(g);
      }/////////////////////////////////

      //if uncle is  NULL
      else if(g->getRight()==NULL){
	////////children/////
	cout<<"CASE5L NO UNCLE"<<endl;
	if(current->getLeft()!=NULL){
          a = current->getLeft();
          aCheck=true;
        }
        if(current->getRight()!=NULL){
          b = current->getRight();
          bCheck=true;
        }
        if(p->getRight()!=NULL){
          c = p->getRight();
          cCheck=true;
        }
       

	/////////

	
	if(g==head){
	  head=p;
	  p->setParent(NULL);
	}
	else if(g!=head){
	  Tree* gp;
	  gp = g->getParent();
	  if(gp->getLeft()==g){
	    gp->setLeft(p);
	    p->setParent(gp);
	  }
	  else if(gp->getRight() == g){
	    gp->setRight(p);
	    p->setParent(gp);
	  }
	}
	p->setLeft(current);
	current->setParent(p);
	p->setRight(g);
	g->setParent(p);

	current->setLeft(NULL);
	current->setRight(NULL);
	g->setLeft(NULL);
	g->setRight(NULL);

	if(aCheck==true){
	  current->setLeft(a);
	  a->setParent(current);
	}
	if(bCheck==true){
	  current->setRight(b);
	  b->setParent(current);
	}
	if(cCheck==true){
	  g->setLeft(c);
	  c->setParent(g);
	}

	recolor(p);
	recolor(g);
      }
      

    }////////////
    //RIGHTTTTTT
    else if(g->getRight()==p && p->getRight()==current && p->getChild()->getColor() == 'R' && current->getChild()->getColor() == 'R'){

      //if uncle is not null but black
      if(g->getLeft()!=NULL && g->getLeft()->getChild()->getColor() == 'B'){
	cout<<"CASE5 R UNCLE"<<endl;
	u = g->getLeft();

	if(u->getLeft()!= NULL){
	  a = u->getLeft();
	  aCheck=true;
	}
	if(u->getRight()!=NULL){
	  b = u->getRight();
	  bCheck=true;
	}
	if(p->getLeft()!=NULL){
	  c=p->getLeft();
	  cCheck=true;
	}
	if(current->getLeft()!=NULL){
	  d=current->getLeft();
	  dCheck=true;
	}
	if(current->getRight()!=NULL){
	  e=current->getRight();
	  eCheck=true;
	}
	



	//////////////////////////////
	if(g==head){
	  head=p;
	  p->setParent(NULL);
	}
	else if(g!=head){
	  Tree* gp=g->getParent();
	  if(gp->getLeft() == g){
	    gp->setLeft(p);
	    p->setParent(gp);
	    
	  }
	  else if(gp->getRight()==g){
	    gp->setRight(p);
	    p->setParent(gp);
	  }
	  
	  
	}
	///////////////////////////
	p->setLeft(g);
	g->setParent(p);
	p->setRight(current);
	current->setParent(p);
	g->setLeft(u);
	u->setParent(g);

	u->setLeft(NULL);
	u->setRight(NULL);
	g->setRight(NULL);
	current->setLeft(NULL);
	current->setRight(NULL);

	if(aCheck==true){
	  u->setLeft(a);
	  a->setParent(u);
	  
	}
	if(bCheck==true){
	  u->setRight(b);
	  b->setParent(u);
	}
	if(cCheck==true){
	  g->setRight(c);
	  c->setParent(g);
	}
	if(dCheck==true){
	  current->setLeft(d);
	  d->setParent(current);
	}
	if(eCheck==true){
	  current->setRight(e);
	  e->setParent(current);
	}

	recolor(p);
	recolor(g);
	
      }
     
      //if uncle is null
      else if(g->getLeft()==NULL){
	cout<<"CASE 5 R NO UNCLE"<<endl;
	
	if(p->getLeft()!=NULL){
          c=p->getLeft();
          cCheck=true;
        }
        if(current->getLeft()!=NULL){
          d=current->getLeft();
          dCheck=true;
        }
        if(current->getRight()!=NULL){
          e=current->getRight();
          eCheck=true;
        }

	
	//////////////////////////////
	if(g==head){
          head=p;
          p->setParent(NULL);
        }
        else if(g!=head){
          Tree* gp=g->getParent();
          if(gp->getLeft() == g){
            gp->setLeft(p);
            p->setParent(gp);
	    
          }
          else if(gp->getRight()==g){
            gp->setRight(p);
            p->setParent(gp);
          }
	}
        /////////////////////////// 

	p->setLeft(g);
	g->setParent(p);
	p->setRight(current);
	current->setParent(p);
	
	g->setLeft(NULL);
	g->setRight(NULL);
	current->setLeft(NULL);
	current->setRight(NULL);

	if(cCheck==true){
          g->setRight(c);
          c->setParent(g);
        }
        if(dCheck==true){
          current->setLeft(d);
          d->setParent(current);
        }
	if(eCheck==true){
          current->setRight(e);
          e->setParent(current);
        }
	recolor(p);
	recolor(g);
	
      }

    }


  }
  // recolor(p);
  // recolor(g);
}


/*
void caseFive(Tree* &head,Tree*current,bool &done){
  Tree* p = NULL;
  Tree* u = NULL;
  Tree* g = NULL;
  Tree* pg = NULL;
  //extra children                                                                                                                               
  Tree* a = NULL;
  bool aCheck = false;
  Tree* b = NULL;
  bool bCheck = false;
  Tree* c = NULL;
  bool cCheck = false;
  Tree* d = NULL;
  bool dCheck = false;
  Tree* e = NULL;
  bool eCheck = false;
  

  
  if(current->getParent()!=NULL && current->getParent()->getParent()!=NULL){

    p = current->getParent();
    g= current->getParent()->getParent();
    //if left left
    if(p->getChild()->getColor()=='R'&&current->getChild()->getColor()=='R'){
      if(g->getLeft() == p && p->getLeft() == current && done!=true){
	cout<<"Left Case 5"<<endl;


	if(g->getRight()!=NULL){
	  u = g->getRight();
	
     
	  
	  //define extra children
	  if(current->getLeft()!=NULL){
	    a=current->getLeft();
	    aCheck=true;
	  }
	  if(current->getRight()!=NULL){
	    b=current->getRight();
	    bCheck=true;
	  }
	  if(p->getRight()!=NULL){
	    c=p->getRight();
	    cCheck=true;
	  }
	  if(u->getLeft()!=NULL){
	    d=u->getLeft();
	    dCheck=true;
	  }
	  if(u->getRight()!=NULL){
	    e=u->getRight();
	    eCheck=true;
	  }

	  
	  if(u->getChild()->getColor() =='B'){
	    if(g==head && done!=true){
	      cout<<"yes"<<endl;
	      head = p;
	      head->setParent(NULL);
	      head->setLeft(current);
	      head->setRight(g);
	      current->setParent(head);
	      g->setParent(head);
	      g->setRight(u);
	      u->setParent(g);
	      
	      current->setLeft(NULL);
	      current->setRight(NULL);
	      g->setLeft(NULL);
	      u->setLeft(NULL);
	      u->setRight(NULL);
	      
	      if(aCheck==true){
		current->setLeft(a);
	      }
	      if(bCheck==true){
		current->setRight(b);
	      }
	      if(cCheck==true){
		g->setLeft(c);
	      }
	      if(dCheck==true){
		u->setLeft(d);
	      }
	      if(eCheck==true){
		u->setRight(e);
	      }
	      recolor(p);
	      recolor(g);
	      done=true;
	    }
	    
	    
	    else if(g!=head && done!=true){
	      pg = g->getParent();
	      if(pg->getLeft()==g){
		pg->setLeft(p);
	      }
	      else if(pg->getRight()==g){
		pg->setRight(p);
	      }
	      p->setParent(pg);
	      p->setLeft(current);
	      p->setRight(g);
	      current->setParent(p);
	      g->setParent(p);
	      g->setRight(u);
	      u->setParent(g);
	      
	      current->setLeft(NULL);
	      current->setRight(NULL);
	      g->setLeft(NULL);
	      u->setLeft(NULL);
	      u->setRight(NULL);
	      
	      if(aCheck==true){
		current->setLeft(a);
	      }
	      if(bCheck==true){
		current->setRight(b);
	      }
	      if(cCheck==true){
		g->setLeft(c);
	      }
	      if(dCheck==true){
		u->setLeft(d);
	      }
	      if(eCheck==true){
		u->setRight(e);
	      }
	      recolor(p);
	      recolor(g);
	      done=true;
	    }
	  }
	}
	else if(g->getRight()==NULL){//WHEN UNCLE IS NULL
	  //define extra children
	  u=NULL;
	  
          if(current->getLeft()!=NULL){
            a=current->getLeft();
            aCheck=true;
          }
          if(current->getRight()!=NULL){
            b=current->getRight();
            bCheck=true;
          }
          if(p->getRight()!=NULL){
            c=p->getRight();
            cCheck=true;
          }
	
	  
            if(g==head && done!=true){
             
              head = p;
              head->setParent(NULL);
              head->setLeft(current);
              head->setRight(g);
              current->setParent(head);
              g->setParent(head);
              g->setRight(NULL);
              u->setParent(g);

              current->setLeft(NULL);
              current->setRight(NULL);
              g->setLeft(NULL);
	      // u->setLeft(NULL);
	      // u->setRight(NULL);

              if(aCheck==true){
                current->setLeft(a);
              }
              if(bCheck==true){
                current->setRight(b);
              }
              if(cCheck==true){
                g->setLeft(c);
              }
              if(dCheck==true){
                u->setLeft(d);
              }
              if(eCheck==true){
                u->setRight(e);
              }
              recolor(p);
              recolor(g);
              done=true;
            }
	    else if(g!=head && done!=true){
              pg = g->getParent();
              if(pg->getLeft()==g){
                pg->setLeft(p);
              }
              else if(pg->getRight()==g){
                pg->setRight(p);
              }
              p->setParent(pg);
              p->setLeft(current);
              p->setRight(g);
              current->setParent(p);
              g->setParent(p);
              g->setRight(NULL);
              u->setParent(g);

              current->setLeft(NULL);
              current->setRight(NULL);
              g->setLeft(NULL);
              //u->setLeft(NULL);
              //u->setRight(NULL);

              if(aCheck==true){
                current->setLeft(a);
              }
              if(bCheck==true){
                current->setRight(b);
              }
              if(cCheck==true){
                g->setLeft(c);
              }
	      //  if(dCheck==true){
              //  u->setLeft(d);
	      // }
	      // if(eCheck==true){
              //  u->setRight(e);
	      // }
              recolor(p);
              recolor(g);
              done=true;
            }
          
	}
      }//
      
      
      //if right right
      else if(g->getRight() == p && p->getRight() == current && done!=true){
	cout<<"Right case 5"<<endl;
	
	if(g->getLeft()!=NULL){
	  u=g->getLeft();
	  
	  
	  
	  
	  //define extra children
	  if(u->getLeft()!=NULL){
	    a = u->getLeft();
	    aCheck=true;
	  }
	  if(u->getRight()!=NULL){
	    b= u->getRight();
	    bCheck = true;
	  }
	  if(p->getLeft()!=NULL){
	    c = p->getLeft();
	    cCheck=true;
	  }
	  if(current->getLeft()!=NULL){
	    d = current->getLeft();
	    dCheck=true;
	  }
	  if(current->getRight()!=NULL){
	    e = current->getRight();
	    eCheck=true;
	  }
	  


      	  if(u->getChild()->getColor()=='B'){
	    if(g==head && done!=true){
	      head = p;
	      p->setParent(NULL);
	      p->setLeft(g);
	      p->setRight(current);
	      current->setParent(p);
	      g->setParent(p);
	      u->setParent(g);
	      g->setLeft(u);    
	      u->setLeft(NULL);
	      u->setRight(NULL);
	      p->setLeft(NULL);
	      current->setLeft(NULL);
	      current->setRight(NULL);
	      if(aCheck==true){
		u->setLeft(a);
		a->setParent(u);
	      }
	      if(bCheck==true){
		u->setRight(b);
		b->setParent(u);
	      }
	      if(cCheck==true){
		p->setLeft(c);
		c->setParent(p);
	      }
	      if(dCheck==true){
		current->setLeft(d);
		d->setParent(current);
	      }
	      if(eCheck==true){
		current->setRight(e);
		e->setParent(current);
	      }
	      recolor(p);
	      recolor(g);
	      done=true;
	    }






	    
	    else if (g!=head && done!=true){
	      pg = g->getParent();
	      if(pg->getLeft()==g){
		pg->setLeft(p);
	      }
	      else if(pg->getRight()==g){
		pg->setRight(p);
	      }
	      
	      p->setParent(pg);
	      p->setLeft(g);
	      p->setRight(current);
	      current->setParent(p);
	      g->setParent(p);
	      u->setParent(g);
	      g->setLeft(u);
	      
	      
	      u->setLeft(NULL);
	      u->setRight(NULL);
	      p->setLeft(NULL);
	      current->setLeft(NULL);
	      current->setRight(NULL);
	      
	      
	      if(aCheck==true){
		u->setLeft(a);
		a->setParent(u);
	      }
	      if(bCheck==true){
		u->setRight(b);
		b->setParent(u);
	      }
	      if(cCheck==true){
		p->setLeft(c);
		c->setParent(p);
	      }
	      if(dCheck==true){
		current->setLeft(d);
		d->setParent(current);
	      }
	      if(eCheck==true){
		current->setRight(e);
		e->setParent(current);
	      }
	      recolor(p);
	      recolor(g);
	      done=true;
	    }
	  }
	}//
	else if(g->getLeft() == NULL){


          //define extra children                                                                                                                

          if(p->getLeft()!=NULL){
            c = p->getLeft();
            cCheck=true;
          }
          if(current->getLeft()!=NULL){
            d = current->getLeft();
            dCheck=true;
          }
          if(current->getRight()!=NULL){
            e = current->getRight();
            eCheck=true;
          }
	  
	  
	  if(g==head && done!=true){
	    head = p;
	    p->setParent(NULL);
	    p->setLeft(g);
	    p->setRight(current);
	    current->setParent(p);
	    g->setParent(p);
	    // u->setParent(g);
	    g->setLeft(NULL);
	    // u->setLeft(NULL);
	    // u->setRight(NULL);
	    p->setLeft(NULL);
	    current->setLeft(NULL);
	    current->setRight(NULL);
	   
	    if(cCheck==true){
	      p->setLeft(c);
	      c->setParent(p);
	    }
	    if(dCheck==true){
	      current->setLeft(d);
	      d->setParent(current);
	    }
	    if(eCheck==true){
	      current->setRight(e);
	      e->setParent(current);
	    }
	    recolor(p);
	    recolor(g);
	    done=true;
	  }
	  
	  else if (g!=head && done!=true){
	    pg = g->getParent();
	    if(pg->getLeft()==g){
	      pg->setLeft(p);
	    }
	    else if(pg->getRight()==g){
	      pg->setRight(p);
	    }
	    
	    p->setParent(pg);
	    p->setLeft(g);
	    p->setRight(current);
	    current->setParent(p);
	    g->setParent(p);
	    //  u->setParent(g);
	    g->setLeft(NULL);
	    
	    
	    // u->setLeft(NULL);
	    // u->setRight(NULL);
	    p->setLeft(NULL);
	    current->setLeft(NULL);
	    current->setRight(NULL);
	    
	    
	   
	    if(cCheck==true){
	      p->setLeft(c);
	      c->setParent(p);
	    }
	    if(dCheck==true){
	      current->setLeft(d);
	      d->setParent(current);
	    }
	    if(eCheck==true){
	      current->setRight(e);
	      e->setParent(current);
	    }
	    recolor(p);
	    recolor(g);
	    done=true;
	  }
	  








	  
	}
	      

	
      }
    }
  }
}
*/

void betterPrint(Tree* &head,Tree* current){
   if(current->getLeft()!=NULL){
    betterPrint(head,current->getLeft());
  }
  cout<<current->getChild()->getRoot()<<current->getChild()->getColor()<<endl;
   if(current->getRight()!=NULL){
    betterPrint(head,current->getRight());
  }

}
/*
void firstCheck(Tree* &head,Tree* current){
  if(current->getLeft()!=NULL){
    firstCheck(head,current->getLeft());
  }
  caseOne(head,current);
  caseRedChildren(head,current);
  


  
  if(current->getRight()!=NULL&& done == false){
    firstCheck(head,current->getRight());
  }
  
}

void recursiveCheck(Tree* &head,Tree* current){
 
 
  if(current->getLeft()!=NULL){
    recursiveCheck(head,current->getLeft());
  }
  printTree2(head,0);
  caseOne(head,current);
  // caseRedChildren(head,current);
  caseThree(head,current);
 
  caseFour(head,current);
  caseFive(head,current,done);
  
  if(current->getRight()!=NULL&& done == false){
    recursiveCheck(head,current->getRight());
  }
  else if(done == true){
    cout<<"lets see if that works"<<endl;
  }
  
}
*/

void correctCheck(Tree* head, Tree* current, bool& finish){
  finish=false;
  cout<<"Current: "<<current->getChild()->getRoot()<<endl;
  printTree2(head,0);
  if(finish == false){
    caseOne(head,current,finish);
  }
  if(finish == false){
    caseTwo(head,current,finish);
  }
  if(finish ==false){
    caseThree(head,current,finish);
  }
  if(finish == false){
    caseFour(head,current,finish);//new finish is new
  // caseFive(head,current,done);
  }
  if(finish==false){//new
    caseFive(head,current);
  }

  cout<<"DONE"<<endl;



  //  caseRedChildren(head,current);
 


}




void recolor(Tree* &input){
  if(input->getChild()->getColor() == 'R'){
    input->getChild()->setColor('B');
  }
  else if(input->getChild()->getColor() == 'B'){
    input->getChild()->setColor('R');
  }

}

