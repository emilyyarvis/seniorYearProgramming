#ifndef MOVIES
#define MOVIES
#include <iostream>

using namespace	std;

class digitalMedia{
  public:
   digitalMedia();
   void setTitle(string input);
  string getTitle();
   void setYear(int input);
   int getYear();
  void setArtist(string input);
  string getArtist();
  void setDuration(int input);
  int getDuration();
  void setPublisher(string input);
  string getPublisher();
  void setDirector(string input);
  string getDirector();
  void setRating(int input);
  int getRating();
 
  protected:
  string title;
  int year; 
  int rating;
  string director;
  int duration;
  string artist;
  string publisher;
};
#endif
