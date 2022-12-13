#include<iostream>
#include"room.h"
#include <map>

using namespace std;

room::room(string description){
  roomDescription = description;
}

string room::getRoomDescription(){
  return roomDescription;
}
void room::setItem(item newItem){

  itemList.push_back(newItem);
}

void room::setExit(string direction,int roomIndex){
  exits.insert(std::pair<string, int>(direction,roomIndex));
}

void room::getExits(){
  int index = exits.size();
  map<string, int>::iterator i;

  
  for (i = exits.begin(); i != exits.end(); i++) {
    cout << i->first << ", "<< i->second<<endl;
  }
}

  
