
#include <iostream>
#include "digitalMedia.h"

using namespace std;

digitalMedia::digitalMedia(){
  cout<<"digitalMedia constructor"<<endl;
  // title = 1;
}
void digitalMedia::setTitle(string input){
  title = input;
}
string digitalMedia::getTitle(){
  return title;
}
void digitalMedia::setYear(int input){
  year=input;
}
int digitalMedia::getYear(){
  return year;
}
void digitalMedia::setArtist(string input){
  artist=input;
}
string digitalMedia:: getArtist(){
  return artist;
}
void digitalMedia:: setDuration(int input){
  duration=input;
}
int digitalMedia::getDuration(){
  return duration;
}
void digitalMedia::setPublisher(string input){
  publisher = input;
}
string digitalMedia::getPublisher(){
  return publisher;
}
void digitalMedia::setDirector(string input){
  director=input;
}
string digitalMedia::getDirector(){
  return director;
}
void digitalMedia::setRating(int input){
  rating=input;
}
int digitalMedia::getRating(){
  return rating;
}
