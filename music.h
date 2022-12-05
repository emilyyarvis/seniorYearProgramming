
#include <iostream>
#include "digitalMedia.h"
using namespace std;

class music:public digitalMedia{
 public:
  music(string inputTitle, int inputYear, string inputArtist, int inutDuration, string inputPublisher);
  ~music();
  // void setArtist(int input);
  // int getArtist();
  // void setDuration(int input);
  // int getDuration();
  //void setPublisher(int input);
  //int getPublisher();
 protected:
  // int artist;
  // int duration;
  // int publisher;
};
