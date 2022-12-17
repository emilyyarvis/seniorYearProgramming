#include <iostream>
#include "room.h"
//#include "item.h"


using namespace std;


int main(){

  vector<string>inventory;
  
  bool loop=true;
  //char userInput[100];
  //create Rooms
  room* mainHall = new room("The Main Hall");
  room* outside= new room("The Outside");
  room* parlor = new room("The Parlor");
  room* garage = new room("The Garage");
  room* movieRoom = new room("The Movie room");
  room* pokerRoom = new room("The Poker Room");
  room* wineCellar = new room("The Wine Cellar");
  room* dungeon = new room("The Dungeon");
  room* diningHall = new room("The Dining Room");
  room* kitchen = new room("The Kitchen");
  room* meatCellar = new room("The Meat Cellar");
  room* bathroom = new room("The Bathroom");
  room* library = new room("The Library");
  room* ballroom = new room("The Ballroom");
  room* balcony = new room("The Balcony");
  room* mirrorRoom = new room("The Room Of Many Mirrors");

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
      cout<<"which direction would you like to go"<<endl;
      cin>> directionInput;
      currentRoom->getSpecificExits(directionInput);
      
    }
    else if(userInput == "INVENTORY"){


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


