
#include <iostream>
#include <cstring>
#include <vector>
#include "movies.h"
#include "music.h"
#include "videoGame.h"
using namespace std;

int main(){
  //initialize needed variables
  int input;
  vector<digitalMedia*>storage;
  bool loop = true;
  string userInput;
  string userInput2;
 
  
  while (loop == true){//while true keep letting user run commands
    cin>>userInput;
    if(userInput== "ADD"){//if User wants to add something to the list
      loop = true;
      bool loop2 =true;
      while(loop2==true){//another loop for typos sake
	//asks what kind of medium to add
	cout<<"What type of media would you like to add?"<<endl;
	cout<<"Type MUSIC for Music, MOVIE for Movies, and VG for Video Games"<<endl;

	cin>>userInput2;
	if(userInput2 == "MUSIC"){//adds music object
	  string inputTitle;
          int inputYear;
          string inputArtist;
          int inputDuration;
          string  inputPublisher;
          loop2 = false;
	  //asks for needed things
          cout<<"Whats the name of your music"<<endl;
          cin>>inputTitle;
          cout<<"Whats the year of your music"<<endl;
          cin>>inputYear;
          cout<<"Whats the Artist of your music"<<endl;
          cin>>inputArtist;
          cout<<"Whats the duration of your music"<<endl;
          cin>>inputDuration;
          cout<<"Whats the publisher of your music"<<endl;
          cin>>inputPublisher;
	  //creates new music objects with correct inputs assigned
          music* mu = new music(inputTitle,inputYear,inputArtist,inputDuration,inputPublisher);
          storage.push_back(mu);//adds it to the list/vector

	}

	else if(userInput2 == "MOVIE"){//adds movie object
	  string inputTitle;
	  int inputYear;
	  int inputRating;
	  string inputDirector;
	  int inputDuration;
	  loop2 = false;
	  //asks for needed inputs
	  cout<<"Whats the name of your movie"<<endl;
	  cin>>inputTitle;
	  cout<<"Whats the year of your movie"<<endl;
          cin>>inputYear;
	  cout<<"Whats the rating of your movie"<<endl;
          cin>>inputRating;
	  cout<<"Whats the director of your movie"<<endl;
          cin>>inputDirector;
	  cout<<"Whats the duration of your movie"<<endl;
          cin>>inputDuration;
	  //creates new movie object with inputs
	  movies* m = new movies(inputTitle,inputYear,inputRating,inputDirector,inputDuration);
          storage.push_back(m);//puts it in vector
	  
	}

	else if(userInput2 == "VG"){//adds video game object
	  string inputTitle;
          int inputYear;
	  string inputPublisher;
	  int inputRating;
          //asks for needed inputs
          loop2 = false;
          cout<<"Whats the name of your game"<<endl;
          cin>>inputTitle;
          cout<<"Whats the year of your game"<<endl;
          cin>>inputYear;
          cout<<"Whats the publisher of your game"<<endl;
          cin>>inputPublisher;
          cout<<"Whats the rating of your game"<<endl;
          cin>>inputRating;
	  //creates videoGame object with inputs
          videoGame* vg = new videoGame(inputTitle,inputYear,inputPublisher, inputRating);
          storage.push_back(vg);//adds it ot the vector
	}
	else{
	  cout<<"That input was not valid please try again"<<endl;
	}
      }
    }


    
    else if(userInput == "PRINT"){//prints out eveyrthing in the vector
      for(int i =0;i<storage.size();i++){
	cout<<"Title: "<<storage[i]->getTitle()<<endl;
	cout<<"Year: "<<storage[i]->getYear()<<endl;
	cout<<"Publisher: "<<storage[i]->getPublisher()<<endl;
	cout<<"Rating: "<<storage[i]->getRating()<<endl;
	cout<<"Director: "<<storage[i]->getDirector()<<endl;
	cout<<"Duration: "<<storage[i]->getDuration()<<endl;
	cout<<" "<<endl;
      }
    }


    
    else if(userInput == "SEARCH"){//searches for something
      bool repeat = true;
      while (repeat == true){//runs a loop so you can search more then once
	string input3;
	cout<<"Would you like to search by a year or a title?"<<endl;
	cout<<"If year input YEAR, if title input TITLE,or EXIT if you would like to Exit"<<endl;
	cin>>input3;//takes in how you want to search
	if(input3=="TITLE"){//if searching by title
	  bool repeat2=true;
	  string inputTitle;
	  char answer;
	  while(repeat2==true){//another loop to search
	    cout<<"What title would you like to search for"<<endl;
	    cin>>inputTitle;//takes in title you are looking for
	    for(int i = 0;i<storage.size();i++){
	      if(storage[i]->getTitle() == inputTitle){//goes through looks for title and prints to user
		cout<<"Title: "<<storage[i]->getTitle()<<endl;
                cout<<"Year: "<<storage[i]->getYear()<<endl;
                cout<<"Publisher: "<<storage[i]->getPublisher()<<endl;
                cout<<"Rating: "<<storage[i]->getRating()<<endl;
                cout<<"Director: "<<storage[i]->getDirector()<<endl;
                cout<<"Duration: "<<storage[i]->getDuration()<<endl;
		cout<<" "<<endl;
		repeat2=false;
	      }
	    }
	    ////////////////////////////////////////////////////////
	    cout<<"do you want to delete the(se) objects(y/n)"<<endl;
	    cin>>answer;
	    if(answer == 'y'){
	      for(int i = 0;i<storage.size();i++){
		if(storage[i]->getTitle() == inputTitle){
		  cout<<"Title: "<<storage[i]->getTitle()<<endl;
		  cout<<"Year: "<<storage[i]->getYear()<<endl;
		  cout<<"Publisher: "<<storage[i]->getPublisher()<<endl;
		  cout<<"Rating: "<<storage[i]->getRating()<<endl;
		  cout<<"Director: "<<storage[i]->getDirector()<<endl;
		  cout<<"Duration: "<<storage[i]->getDuration()<<endl;
		  // storage.remove(1);//need to fix this
		}
	      }  
	      
	    }
	    else{
	      cout<<"Ok I wont"<<endl;
	    }
	    ///////////////////////////////////////////////////////////
	  }
	}
	else if(input3=="YEAR"){//same thing but searching by year
	  bool repeat2=true;
          int inputYear;
	  char answer;
          while(repeat2==true){

            cout<<"What year would you like to search for"<<endl;
            cin>>inputYear;
            for(int i = 0;i<storage.size();i++){//goes through whole list and if year matches with inputted year will ask user if they want to delete
	      if(storage[i]->getYear() == inputYear){
		cout<<"Title: "<<storage[i]->getTitle()<<endl;
                cout<<"Year: "<<storage[i]->getYear()<<endl;
                cout<<"Publisher: "<<storage[i]->getPublisher()<<endl;
                cout<<"Rating: "<<storage[i]->getRating()<<endl;
                cout<<"Director: "<<storage[i]->getDirector()<<endl;
                cout<<"Duration: "<<storage[i]->getDuration()<<endl;
                repeat2=false;
	      }
	    }
	    ////////////////////////////////////////////////////////                        
            cout<<"do you want to delete the(se) objects(y/n)"<<endl;
            cin>>answer;
            if(answer == 'y'){
              for(int i = 0;i<storage.size();i++){
                if(storage[i]->getYear() == inputYear){
                  cout<<"Title: "<<storage[i]->getTitle()<<endl;
                  cout<<"Year: "<<storage[i]->getYear()<<endl;
                  cout<<"Publisher: "<<storage[i]->getPublisher()<<endl;
                  cout<<"Rating: "<<storage[i]->getRating()<<endl;
                  cout<<"Director: "<<storage[i]->getDirector()<<endl;
                  cout<<"Duration: "<<storage[i]->getDuration()<<endl;
                  // storage.remove(1);//need to fix this                                   
                }
              }

            }
            else{
              cout<<"Ok I wont"<<endl;
            }
            ///////////////////////////////////////////////////////////    
	  }
	}
	else if(input3 =="EXIT"){//if the user wants to exit
	  repeat=false;
	}
	else{
	  cout<<"This was an invalid input try again please"<<endl;
	}

      }

    }

    else if(userInput=="DELETE"){//directs user to how they can delete things(was more efficient to code this way)
      //cout<<"use the search function to delete items"<<endl;
      string input;
      //mediaTypes::iterator it;
      cout<<"Please enter the title of media you would like to delete"<<endl;
      cin>>input;
      for(int i = 0; i<storage.size();i++){
	if(input == storage[i]->getTitle()){
	  int index =i;
	  storage.erase(storage.begin() +index);
	  cout<<input<<" has been removed"<<endl;
	}
	else{
	  cout<<"this title could not be found"<<endl;
	}
      }
    }
    else if(userInput =="BREAK"){//if at anytime the user wants to stop
      break;
    
    }
  }
}
