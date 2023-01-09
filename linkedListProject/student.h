#include<iostream>
using namespace std;

class student{

 public:
  student(int newId);
  int getId();
  void setId(int newId);
 private:
  int id;
};
