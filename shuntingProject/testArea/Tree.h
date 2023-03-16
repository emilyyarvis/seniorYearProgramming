#include <iostream>
 #include <cstring>
 #include "Child.h"

 class Tree {
 public:
   Tree(Child* inputRoot);
   ~Tree();
   Child * getChild();
  
   
 private:
   Child* root;
   Tree* right;
   Tree* left;
 };
