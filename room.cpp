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

bool room::removeItem(string inputItem){
  //bool itemRemoved=false;;
  for(int i=0; i<itemList.size();i++){
    if(itemList[i]->getItemName()==inputItem){
      int index = i;
      itemList.erase(itemList.begin()+index);
      cout<<itemList[i]->getItemName()<<" has been added to your inventory"<<endl;
      return true;
    }
  }
  cout<<"This item is not in the room"<<endl;
  return false;
}
bool room::checkForItem(string inputItem){

for(int i=0; i<itemList.size();i++){
  if(itemList[i]->getItemName()== inputItem){
    return true;   
  }
 }
 return false;
}


void room::getRoomItems(){
  for(int i=0; i<itemList.size();i++){
    cout<<"-"<<itemList[i]->getItemName()<<endl;
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

void room::getSpecificExits(string direction){

 map<string, room*>::iterator i;


  for (i = exits.begin(); i != exits.end(); i++) {
    if(i->first == direction){
      cout<< i->second->getRoomDescription()<<endl;
      //return i->second->getRoomDescription();
	}
  }
  
}
  
