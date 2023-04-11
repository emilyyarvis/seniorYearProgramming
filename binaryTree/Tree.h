#include <iostream>
 #include <cstring>
 #include "child.h"

 class Tree {
 public:
   Tree(Child* inputRoot);//Tree constructor
   ~Tree();
   Child * getChild();//returns child of Tree(which holds root/value)
   Tree* getRight();//returns right branch fo tree
   Tree* getLeft();//returns left rbanch of tree
   void setRight(Tree* rightInput);//sets right branch of tree
   void setLeft(Tree* leftInput);//sets left branch of tree
   Tree* getParent();
   void setParent(Tree* parent);
 private:
   Child* root;//assigned value of tree
   Tree* right;//right branch
   Tree* left;//left branch
   Tree* parent;
 };
