#include <iostream>
#include "stu.h"

Student::Student(int inputId){
  id = inputId;

}

Student::~Student(){


}
void Student::setId(int inputId){
  id = inputId;

}

int Student::getId(){
  return id;

}
