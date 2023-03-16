
#include<iostream>
#include"Tree.h"

using namespace std;

Tree::Tree(Child* inputRoot){
  root= inputRoot;
  left=NULL;
  right = NULL;
}

Tree::~Tree(){
  delete root;
  left =NULL;
  right = NULL;
  
}
Child* Tree::getChild(){
  return root;

}
