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
  bool removeItem(string  inputItemx);
  bool checkForItem(string inputItem);
  void getRoomItems();
  void setExit(string direction, room* roomIndex);
  void getExits();
  string getSpecificExits(string direction);
  
 private:
  string roomDescription;
  vector<item*>itemList;
  map<string, room*> exits;
  
};
