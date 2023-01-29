#include <iostream>
#include "stu.h"
#include <cstring>

using namespace std;

Student::Student(int inputId,float inputGPA,string inputFirstName,string inputLastName){
  id = inputId;
  GPA = inputGPA;
  firstName = inputFirstName;
  lastName= inputLastName;
}

Student::~Student(){


}
void Student::setFirstName(string inputFirstName){
  firstName = inputFirstName;
}
string Student::getFirstName(){
  return firstName;
}
void Student::setLastName(string inputLastName){

}
string Student::getLastName(){
  return lastName;
}
void Student::setId(int inputId){
  id = inputId;

}

int Student::getId(){
  return id;

}
void Student::setGPA(float inputGPA){

  GPA = inputGPA;
}

float Student::getGPA(){
  return GPA;
}
