#include<iostream>
#include"videoGame.h"

using namespace std;

videoGame::videoGame(string inputTitle, int inputYear, string inputPublisher, int inputRating){
  cout<<"video game constructor"<<endl;
  title = inputTitle;
  year=inputYear;
  publisher=inputPublisher;
  rating=inputRating;

}
//void videoGame::setRating(int input){

//}

//int videoGame::getRating(){

//return rating;

//}

//void videoGame::setPublisher(int input){

//}
//int videoGame::getPublisher(){

//  return publisher;
//}
