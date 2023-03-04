#include <iostream>
 #include <cstring>
 #include "stu.h"

 class Node {
 public:
   Node(Student* student);
   ~Node();
   
   Student * getStudent();
   void setRight(Node* node);
   void setLeft(Node* node);
   Node * getRight();
   Node* getLeft();
   
 private:
   Student* student;
   Node* right;
   Node* left;
   
 };
