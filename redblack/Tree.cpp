
#include<iostream>
#include"Tree.h"

using namespace std;

Tree::Tree(Child* inputRoot){
  root= inputRoot;
  left=NULL;
  right = NULL;
  parent = NULL;
}

Tree::~Tree(){
  delete root;
  left =NULL;
  right = NULL;
  
}
Child* Tree::getChild(){
  return root;

}


Tree* Tree::getRight(){
  return right;
}

Tree* Tree::getLeft(){
  return left;
}

void Tree::setRight(Tree* rightInput){
  right = rightInput;

}

void Tree::setLeft(Tree* leftInput){
  left=leftInput;
  
}
Tree* Tree:: getParent(){
  return parent;
}

void Tree::setParent(Tree* inputParent){

  parent = inputParent;
}
