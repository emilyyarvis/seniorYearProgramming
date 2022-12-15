#include<iostream>
#include"item.h"
#include<cstring>

using namespace std;

item::item(string name){
  itemName = name;

}
string item::getItemName(){

  return itemName;
}
