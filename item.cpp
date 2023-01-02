#include<iostream>
#include"item.h"
#include<cstring>

using namespace std;

item::item(string name){//item constructor
  itemName = name;

}
string item::getItemName(){//returns name of item

  return itemName;
}
