#include <iostream>
#include "child.h"
#include <cstring>

using namespace std;

Child::Child(int inputValue){
  value = inputValue;
  color = 'R';
  nullity = false;
}

Child::~Child(){

}

void Child::setRoot(int inputValue){
  value = inputValue;

}

int Child::getRoot(){
  return value;

}

char Child:: getColor(){
  return color;

}
void Child::setColor(char inputColor){
  color = inputColor;
}

bool Child::getNull(){
  return nullity;
}

void Child::setNull(bool inputNull){
  nullity = inputNull;
}
