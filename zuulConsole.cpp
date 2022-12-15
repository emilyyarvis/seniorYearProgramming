#include <iostream>
#include "room.h"
//#include "item.h"


using namespace std;


int main(){

  bool loop=true;
  char userInput[100];
  //create Rooms
  room* mainHall = new room("Look my first room");
  room* outside= new room("This is the outside");
  room* parlor = new room("this is the parlor");
  room* garage = new room("this is a garage");
  room* movieRoom = new room("this is the movie room");
  room* pokerRoom = new room("This is the poker room");
  room* wineCellar = new room("This is the wine cellar");
  room* dungeon = new room("this is the dungeon");
  room* diningHall = new room("this is the dining room");
  room* kitchen = new room("this is the kitchen");
  room* meatCellar = new room("this is the kitchen");
  room* bathroom = new room("this is the bathroom");
  room* library = new room("this is the library");
  room* ballroom = new room("this is the ballroom");
  room* balcony = new room("this is the balcony");
  room* mirrorRoom = new room("This is the room of many mirrors");
  
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
  
  garage->removeItem(avocado);
  
  while(loop == true){
    cout<<"Insert instructions here"<<endl;
    cin.get(userInput,100);
    if(strcmp(userInput,"EXIT")==0){
      loop = false;
    }
    else if(strcmp(userInput,"GO")==0){
      cout<<"something soon"<<endl;
    }
    else if(strcmp(userInput, "GET")==0){
	cout<<"somethig soon"<<endl;
      }
    else{
      cout<<"thta is not a valid command"<<endl;
    }
  }
}


