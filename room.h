#include<iostream>
#include "item.h"
#include <vector>
#include <map>
using namespace std;

class room{
 public:
  room(string description);
  void setItem(item newItem );
  void getItemName();
  void setExit();
  void getExits();
  
 private:
  string roomDescription;
  vector<item>itemList;
};
