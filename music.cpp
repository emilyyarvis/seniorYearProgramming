#include<iostream>
#include "music.h"
using namespace std;

music::music(string inputTitle, int inputYear, string inputArtist, int inputDuration, string inputPublisher){
  cout<<"music constructor"<<endl;
  title= inputTitle;
  year=inputYear;
  artist=inputArtist;
  duration=inputDuration;
  publisher=inputPublisher;

}
//void music::setArtist(int input){

//}
//int music::getArtist(){
//  return artist;
//}
//void music::setDuration(int input){

//}
//int music::getDuration(){
//  return duration;
//}
//void music::setPublisher(int input){

//}

//int music::getPublisher(){
//  return publisher;
//}

