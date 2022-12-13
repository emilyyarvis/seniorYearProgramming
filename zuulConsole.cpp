#include <iostream>
#include "room.h"
//#include "item.h"


using namespace std;


int main(){

  bool loop;
  char userInput[100];
  //create Rooms
  room* mainHall = new room("Look my first room");
  room* bounceyHouse = new room("This is a room");
  room* parlor = new room("this is the parlor");
  cout<<mainHall->getRoomDescription()<<endl;
  //
  mainHall->setExit("North", 2);
  mainHall->setExit("West",1);
  mainHall->getExits();
  
  // bounceyHouse->setExit("North", 20);
  // bounceyHouse->setExit("West", 40);
  //bounceyHouse->getExits();


  //
  cout<<"did it work"<<endl;
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


