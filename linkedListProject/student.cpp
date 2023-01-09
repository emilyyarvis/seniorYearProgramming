#include<iostream>
#include"student.h"
using namespace std;

student::student(int newId){
  id=newId;
}
int student::getId(){
  return id;
}

void student::setId(int newId){
  id=newId;
}
