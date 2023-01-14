#include<iostream>
using namespace std;

class student{

 public:
  student(int newId);//student constructor
  int getId();//gets the id of the student
  void setId(int newId);//sets the id of the student
 private:
  int id;//the id of the student
};
