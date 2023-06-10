#include<iostream>
//#include "vertex.h"
using namespace std;

class edge{
public:
  edge(int inputWeight, vertex* inputPoint1, vertex* inputPoint2);
  vertex* getPoint1();
  vertex* getPoint2();
  void setPoint1(vertex* inputPoint);
  void setPoint2(vertex* inputPoint);
  int getWeight();
  void setWeight(int inputWeight);
private:
  int weight;
  vertex* point1;
  vertex* point2;
};