#include <iostream>
#include "digitalMedia.h"
using namespace std;

class videoGame : public digitalMedia{
 public:
  videoGame(string inputTitle, int inputYear, string inputPublisher, int inputRating);
  ~videoGame();
  //  void setRating(int input);
  // int getRating();
  // void setPublisher(int input);
  //int getPublisher();
 protected:
  // int rating;
  // int publisher;
};
