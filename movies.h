#include <iostream>
#include "digitalMedia.h"
using namespace std;

class movies : public digitalMedia{
 public:
  movies(string inputTitle,int inputYear,int inputRating, string inputDirector, int inputDuration);
  ~movies();
  // void setDirector(int input);
  // int getDirector();
  // void setRating(int input);
  // int getRating();
  // void setDuration(int input);
  // int getDuration();
  
 protected:
  // int rating;
  // int director;
  // int duration;
};
