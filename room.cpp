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
void room::setItem(item* newItem){
  itemList.push_back(newItem);
}

void room::removeItem(item* newItem){
  for(int i=0; i<itemList.size();i++){
    if(newItem == itemList[i]){
      cout<<"yay"<<endl;
    }
  }
}

void room::getRoomItems(){
  for(int i=0; i<itemList.size();i++){
    cout<<itemList[i]->getItemName()<<", "<<endl;
  }
}

void room::setExit(string direction,room* roomIndex){
  exits.insert(std::pair<string, room*>(direction,roomIndex));
}

void room::getExits(){
  int index = exits.size();
  map<string, room*>::iterator i;

  
  for (i = exits.begin(); i != exits.end(); i++) {
    cout << i->first << ", "<< i->second<<endl;
  }
}

  
