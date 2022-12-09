#include<iostream>
#include"room.h"


using namespace std;

room::room(string description){
  roomDescription = description;
}

void room::setItem(item newItem){

  itemList.push_back(newItem);

}
