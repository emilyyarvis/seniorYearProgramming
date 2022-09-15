#include <iostream>
//This game will have the user guess a number between 1-100.
//Author: Emily Yarvis
// Date: 9/13/22
//1. No global variables. (Global constants are all right.)
//2. No strings. Not ever. (You can use cstring
//3. You should include <iostream>, not stdio. (This applies more to C programmers.)
//
//
using namespace std;
//initializes variables
int randomNumber=0;
int guess =0;
int numGuesses = 0;
bool guessed = false;
bool playAgain = false;
char answer ='a';
int PLAYING = 4;
int GUESSED = 5;
int DONE = 6;
int state = 7;
int main(){

  //creates the random number
  srand(time(NULL));
  randomNumber = (rand()%100);
  cout << randomNumber << endl; 

  while (guessed == false){//while the user has not guessed the number
    state = PLAYING;
    cout << "Guess a Number Between 0-100" << endl;//asks you to enter a number
    cin >> guess;//takes in a number from the user
    if(guess != randomNumber){//if it doesnt equal the random number finds out if its a valid guess or not
      if(guess <0 || guess>100){//in valid
	cout << "That is not a valid guess try again" << endl;
      }
      else if(guess> randomNumber){//valid and too high
	cout<< "That number is higher then the random number, try again"<<endl;
	++numGuesses;
      }
      else if(guess < randomNumber){//valid and too low
	cout << "That number is lowew then the random number, try again" <<endl;
	++numGuesses;
      }
      else{//invalid
	cout << "That is not a valid guess try again" << endl;
      }
    }
    else if(guess == randomNumber){//if the guess is the random number
      ++numGuesses;
      cout << "You Guessed The Number"<< endl;
      cout << "It took you " << numGuesses <<endl;

      guessed = true;//sets that you guessed the number and ends the while loop
      state = GUESSED;

    }
  }
  //asks if you want to play again
  while(state == GUESSED){
    cout << "want to play again?" << endl;
    cout << "answer y or n" << endl;
    cin >> answer;
    if(answer == 'n'){
      cout << "whelp goodbye"<<endl;
      state= DONE;
    }
    else if(answer == 'y'){
      state = PLAYING;
      cout<< "lets do it" << endl;
      //resets all variables for new game
      guessed = false;
      numGuesses = 0;
      main();//runs main again/runs game again
      
    }
    else{
      cout<< "this isnt a valid response"<< endl;
    }
  }  
  return 0;
}
 
