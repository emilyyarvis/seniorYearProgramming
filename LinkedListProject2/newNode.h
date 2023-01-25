#include <iostream>
 #include <cstring>
 #include "stu.h"

 class Node {
 	public:
 		Node(Student * student);
 		~Node();

 		Student * getStudent();
 		void setNext(Node * node);
 		Node * getNext();

 	private:
 		Student * student;
 		Node * next;
 };
