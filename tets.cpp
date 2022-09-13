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
int randomNumber=0;
int guess =0;
int numGuesses = 0;
bool guessed = false;
bool playAgain = false;
char answer ='a';

int main(){

  srand(time(NULL));
  randomNumber = (rand()%100);
  cout << randomNumber << endl; 

  while (guessed == false){
    cout << "Guess a Number Between 0-100" << endl;
    cin >> guess;
    if(guess != randomNumber){
      if(guess <0 || guess>100){
	cout << "That is not a valid guess try again" << endl;
      }
      else if(guess> randomNumber){
	cout<< "That number is higher then the random number, try again"<<endl;
	++numGuesses;
      }
      else if(guess < randomNumber){
	cout << "That number is lowerw then the random number, try again" <<endl;
	++numGuesses;
      }
      else{
	cout << "That is not a valid guess try again" << endl;
      }
    }
    else if(guess == randomNumber){
      ++numGuesses;
      cout << "You Guessed The Number"<< endl;
      cout << "It took you " << numGuesses <<endl;

      guessed = true;
    }
  }
  cout << "want to play again?" << endl;
  cout << "answer y or n" << endl;
  cin >> answer;
  if(answer == 'n'){
    cout << "whelp goodbye"<<endl;
  }
  else if(answer == 'y'){
    cout<< "lets do it" << endl;
    guessed = false;
    numGuesses = 0;
    main();

  }
  
  else{
    cout<< "this isnt a valid response"<< endl;
  }
			   
  return 0;
}
 
