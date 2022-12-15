#include<iostream>
#include "item.h"
#include <vector>
#include <map>
using namespace std;

class room{
 public:
  room(string description);
  string getRoomDescription();
  void setItem(item* newItem );
  void removeItem(item* newItem);
  void getRoomItems();
  void setExit(string direction, room* roomIndex);
  void getExits();
  
 private:
  string roomDescription;
  vector<item*>itemList;
  map<string, room*> exits;
};
