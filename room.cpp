#include<iostream>
#include"room.h"
#include <map>

using namespace std;

room::room(string description){//room constructor
  roomDescription = description;
}

string room::getRoomDescription(){//returns room description
  return roomDescription;
}
void room::setItem(item* newItem){//sets item to a room
  itemList.push_back(newItem);
}

bool room::removeItem(string inputItem){//removed item from room
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
bool room::checkForItem(string inputItem){//checks too see if item is in room

for(int i=0; i<itemList.size();i++){
  if(itemList[i]->getItemName()== inputItem){
    return true;   
  }
 }
 return false;
}


void room::getRoomItems(){//gets items in a room
    for(int i=0; i<itemList.size();i++){
    cout<<"-"<<itemList[i]->getItemName()<<endl;
  }
}

void room::setExit(string direction,room* roomIndex){//sets exits
  exits.insert(std::pair<string, room*>(direction,roomIndex));
}

void room::getExits(){//gets room exits
  int index = exits.size();
  map<string, room*>::iterator i;

  
  for (i = exits.begin(); i != exits.end(); i++) {
    cout << i->first <<endl;
  }
}

string room::getSpecificExits(string direction){//returns room exits

 map<string, room*>::iterator i;
 string description;

  for (i = exits.begin(); i != exits.end(); i++) {
    if(i->first == direction){
      description=i->second->getRoomDescription();
      
	}
  }
  return description;
}
  
