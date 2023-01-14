#include <iostream>
#include "room.h"
//#include "item.h"


using namespace std;


int main(){

  vector<string>inventory;
  vector<room*>roomList;
  
  bool loop=true;
  bool win=false;
 
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
  
  currentRoom = outside;
 
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
  //
  pokerRoom->setExit("north", wineCellar);
  pokerRoom->setExit("west", movieRoom);
  //
  wineCellar->setExit("south", pokerRoom);
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
  
  //setItems
  item* key = new item("key");
  item* book = new item("book");
  item* mirror = new item("mirror");
  item* wine = new item("wine");
  item* hammer = new item("hammer");
  item* fork = new item("fork");
  item* knife = new item("knife");
  item* dvd = new item("Old Movie");
  item* avocado = new item("Avocado");
  item* corpse = new item("Hanging Corpse");
  item* Mysterious_Box = new item("Mysterious_Box");
  //
  outside->setItem(Mysterious_Box);
  bathroom->setItem(key);
  mirrorRoom->setItem(mirror);
  library->setItem(book);
  diningHall->setItem(fork);
  kitchen->setItem(knife);
  kitchen->setItem(avocado);
  meatCellar->setItem(corpse);
  wineCellar->setItem(wine);
  movieRoom->setItem(dvd);
  garage->setItem(hammer);

  //initial instructions
cout<<"Welcome to mystery mansion, see this mysterious box here, in order to leave mystery manor, you must obtain the key that opens this box."<<endl;
 cout<<"Obtain the key by moving about the manison using the GO command and collecting items to help you find the key!"<<endl;
 cout<<"For help at any time type HELP and if you wish to quit the game at any time type EXIT. Good Luck!"<<endl;

 //gameplay
  while(loop == true){
    cout<<endl;
    cout<<"You are in "<<currentRoom->getRoomDescription()<<endl;
    cout<<"Exits: "<<endl;
    currentRoom->getExits();
    cout<<endl;
    cout<<"Items in the room:"<<endl;
    currentRoom->getRoomItems();

     if(currentRoom == outside){//checks win   
      for(int i=0; i<inventory.size();i++){
        if(inventory[i] == "key"){
          loop = false;
          cout<<"Congratualtions, you found the key to open the box and you have no escaped from Mystery Manor! Press any key to end the day"<<endl;
          break;
        }
      }
    }
    
    string userInput;
    cin>>userInput;//takes in commands from the user
    
    if(userInput == "EXIT"){//if command is EXIT, quits the game
      loop = false;
    }
    else if(userInput == "GO"){//if the command is GO
      string directionInput;
      int index=0;
      bool found=false;
      cout<<"which direction would you like to go"<<endl;
      cin>> directionInput;//takes in direction
      for(int i=0;i<roomList.size();i++){//moves you if logically possible
	if(roomList[i]->getRoomDescription() == currentRoom->getSpecificExits(directionInput)){
	  index = i;
	  found=true;
	}
      }
      if(found == true){
	currentRoom = roomList[index];
      }
      else if(found == false){
	cout<<"there is nowhere to go in that direction"<<endl;
      }
    }
    else if(userInput == "INVENTORY"){//if command is INVENTORY prints out inventory
      cout<<"Items in your inventory: "<<endl;
      for(int i=0;i<inventory.size();i++){
	cout<<inventory[i]<<endl;
      }
      cout<<endl;
    }
    else if(userInput == "DROP"){//if command is DROP 
      string dropItem;
      bool found = false;
      string droppedItem;
      cout<<"What item would you like to drop?"<<endl;
      cin>>dropItem;//takes in item you would like to drop
      for(int i=0;i<inventory.size();i++){
        if(inventory[i] == dropItem){//sees if item can be dropped and drops it
	  int index =i;
          inventory.erase(inventory.begin() +index);//erases it from the list 
	  cout<<dropItem<<" has been removed"<<endl;
	  droppedItem = inventory[i];
	  found = true;
	  item* newItem = new item(droppedItem);
	  currentRoom->setItem(newItem);
	}
      }
      if(found == false){//if item cannot be dropped
	cout<<"That item is not in your inventory"<<endl;
      }
    }
    else if(userInput == "HELP"){//if command is HELP prints instrcutions
      cout<<endl;
      cout<<"Instructions: "<<endl;
      cout<<"Move around the room using commands to pick up important items to win the game"<<endl;
      cout<<"Commands: "<<endl;
      cout<<"-GO: pair with north/south/east/west to move about the rooms"<<endl;
      cout<<"-GET: pair with an item in a room to pick up an item"<<endl;
      cout<<"-INVENTORY: see whats in your inventory"<<endl;
      cout<<"-DROP: pair with an item in your inventory to drop said item"<<endl;
      cout<<"-EXIT: to quit playing the game"<<endl;
      cout<<"-HELP: to see this list of instructions again"<<endl;
      cout<<endl;
    }
    else if(userInput =="GET"){//if command is GET
      string itemInput;
      cout<<"Which item would you like to pick up"<<endl;
      cin>>itemInput;//takes in item you would like to get
      
      if(currentRoom->checkForItem(itemInput) == true){//sees if you can get it
	currentRoom->removeItem(itemInput);
	inventory.push_back(itemInput);//adds to inventory if you can
      }
      else if(currentRoom->checkForItem(itemInput) == false){//prints if you cant
	cout<<"This item is not in this room"<<endl;
      }
    }
    
    else{//command inputted was not a valid command
      cout<<"That is an invalid command please try again"<<endl;
    }
    
  }
}


