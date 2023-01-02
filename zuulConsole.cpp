#include <iostream>
#include "room.h"
//#include "item.h"


using namespace std;


int main(){

  vector<string>inventory;
  vector<room*>roomList;
  
  bool loop=true;
  //char userInput[100];
  //create Rooms
  room* mainHall = new room("The Main Hall");
  roomList.push_back(mainHall);
  room* outside= new room("The Outside");
  roomList.push_back(outside);
  room* parlor = new room("The Parlor");
  roomList.push_back(parlor);
  room* garage = new room("The Garage");
  roomList.push_back(garage);
  room* movieRoom = new room("The Movie room");
  roomList.push_back(movieRoom);
  room* pokerRoom = new room("The Poker Room");
  roomList.push_back(pokerRoom);
  room* wineCellar = new room("The Wine Cellar");
  roomList.push_back(wineCellar);
  room* dungeon = new room("The Dungeon");
  roomList.push_back(dungeon);
  room* diningHall = new room("The Dining Room");
  roomList.push_back(diningHall);
  room* kitchen = new room("The Kitchen");
  roomList.push_back(kitchen);
  room* meatCellar = new room("The Meat Cellar");
  roomList.push_back(meatCellar);
  room* bathroom = new room("The Bathroom");
  roomList.push_back(bathroom);
  room* library = new room("The Library");
  roomList.push_back(library);
  room* ballroom = new room("The Ballroom");
  roomList.push_back(ballroom);
  room* balcony = new room("The Balcony");
  roomList.push_back(balcony);
  room* mirrorRoom = new room("The Room Of Many Mirrors");
  roomList.push_back(mirrorRoom);
  room* currentRoom;

  currentRoom = garage;
  currentRoom->getRoomItems();
  //cout<<mainHall->getRoomDescription()<<endl;
  
  //intialize exits
  mainHall->setExit("south", outside);
  mainHall->setExit("west",parlor);
  mainHall->setExit("east", diningHall);
  //
  outside->setExit("north", mainHall);
  outside->setExit("west",garage);
 
  //
  parlor->setExit("south", garage);
  parlor->setExit("north",movieRoom);
  parlor->setExit("east", mainHall);
  //
  garage->setExit("north", parlor);
  garage->setExit("east",outside);
  //
  movieRoom->setExit("south", parlor);
  movieRoom->setExit("east",pokerRoom);
  //movieRoom->setExit("east", diningHall); secret room
  //
  pokerRoom->setExit("north", wineCellar);
  pokerRoom->setExit("west", movieRoom);
  //

  //dungeon

  //
  wineCellar->setExit("south", pokerRoom);
  //mainHall->setExit("west",dungeon);
  
  //
  diningHall->setExit("south", kitchen);
  diningHall->setExit("west",mainHall);
  diningHall->setExit("north", library);
  //
  library->setExit("north", mirrorRoom);
  library->setExit("west",ballroom);
  library->setExit("east", bathroom);
  library->setExit("south",diningHall);
  //
  ballroom->setExit("north", balcony);
  ballroom->setExit("east", library);
  //
  balcony->setExit("south", ballroom);
  balcony->setExit("east", mirrorRoom);
  //
  bathroom->setExit("west", library);
  //
  mirrorRoom->setExit("south", library);
  mirrorRoom->setExit("west",balcony);
 
  //
  kitchen->setExit("north", diningHall);
  kitchen->setExit("west",meatCellar);
  //
  meatCellar->setExit("east", kitchen);
  //
  //
  item* knife = new item("Knife");
  item* workBench = new item("workBench");
  item* hammer = new item("hammer");
  item* form = new item("fork");
  item* table = new item ("table");
  item* projector = new item("projector");
  item* couch = new item("couch");
  item* sign = new item("key sign");
  item* dvd = new item("Old Movie");
  item* avocado = new item("Avocado");
  item* counterTop = new item("Countertop");
  item* corpse = new item("Hanging Corpse");
  
  //
  garage->setItem(workBench);
  garage->setItem(hammer);
  parlor->setItem(dvd);
  parlor->setItem(avocado);
  //currentRoom->getRoomItems();
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);
  //
  //kitchen->setItem(knife);
  //kitchen->setItem(Avocado);

  //garage->getRoomItems();
  //cout<<""<<endl;
  //garage->removeItem(hammer);
  //garage->getRoomItems();

  
  while(loop == true){
    cout<<"Insert instructions here"<<endl;
    cout<<"You are in "<<currentRoom->getRoomDescription()<<endl;
    cout<<"Items in the room:"<<endl;
    currentRoom->getRoomItems();

    string userInput;
    cin>>userInput;
    if(userInput == "EXIT"){
      loop = false;
    }
    else if(userInput == "GO"){
      string directionInput;
      int index=0;
      cout<<"which direction would you like to go"<<endl;
      cin>> directionInput;
       cout<<currentRoom->getSpecificExits(directionInput)<<endl;
       cout<<roomList[1]->getRoomDescription()<<endl;
      for(int i=0;i<roomList.size();i++){
	if(roomList[i]->getRoomDescription() == currentRoom->getSpecificExits(directionInput)){
	  cout<<roomList[i]->getRoomDescription()<<endl;
	  cout<<currentRoom->getSpecificExits(directionInput)<<endl;
	  index = i;
	}
      }
      currentRoom = roomList[index];
    }
    else if(userInput == "INVENTORY"){
      cout<<"Items in your inventory: "<<endl;
      for(int i=0;i<inventory.size();i++){
	cout<<inventory[i]<<endl;
      }
      cout<<endl;
    }
    else if(userInput == "DROP"){
      string dropItem;
      bool found = false;
      string droppedItem;
      cout<<"What item would you like to drop?"<<endl;
      cin>>dropItem;
      for(int i=0;i<inventory.size();i++){
        if(inventory[i] == dropItem){
	  int index =i;
          inventory.erase(inventory.begin() +index);//erases it from the list 
	  cout<<dropItem<<" has been removed"<<endl;
	  droppedItem = inventory[i];
	  found = true;
	  item* newItem = new item(droppedItem);
	  currentRoom->setItem(newItem);
	}
      }
      if(found == false){
	cout<<"That item is not in your inventory"<<endl;
      }
    }
    else if(userInput =="GET"){
      string itemInput;
      cout<<"Which item would you like to pick up"<<endl;
      cin>>itemInput;
      
      if(currentRoom->checkForItem(itemInput) == true){
	currentRoom->removeItem(itemInput);
	inventory.push_back(itemInput);
      }
      else if(currentRoom->checkForItem(itemInput) == false){
	cout<<"This item is not in this room"<<endl;
      }
    }
    else{
      cout<<"That is an invalid command please try again"<<endl;
    }
    
  }
}


