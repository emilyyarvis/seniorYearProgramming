#include <iostream>
 #include <cstring>
 #include "Child.h"

 class Tree {
 public:
   Tree(Child* inputRoot);
   ~Tree();
   Child * getChild();
   Tree* getRight();
   Tree* getLeft();
   void setRight(Tree* rightInput);
   void setLeft(Tree* leftInput);
   
 private:
   Child* root;
   Tree* right;
   Tree* left;
 };
