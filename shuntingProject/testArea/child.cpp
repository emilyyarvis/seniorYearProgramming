#include <iostream>
#include "Child.h"
#include <cstring>

using namespace std;

Child::Child(char inputValue){
  value = inputValue;
}

Child::~Child(){

}

void Child::setRoot(char inputValue){
  value = inputValue;

}

char Child::getRoot(){
  return value;

}

