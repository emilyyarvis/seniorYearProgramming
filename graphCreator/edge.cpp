#include <iostream>
#include "vertex.h"
#include "edge.h"

using namespace std;

edge::edge(int inputWeight, vertex* inputPoint1, vertex* inputPoint2){
    
    weight = inputWeight;
    point1 = inputPoint1;
    point2 = inputPoint2;
    
}

vertex* edge::getPoint1(){
    return point1;
}

vertex* edge::getPoint2(){
    return point2;
    
}
void edge::setPoint1(vertex* inputPoint){
    point1 = inputPoint;
    
}
void edge::setPoint2(vertex* inputPoint){
    point2 = inputPoint;
    
}
int edge::getWeight(){
    return weight;
    
}
void edge::setWeight(int inputWeight){
    weight = inputWeight;
    
}
