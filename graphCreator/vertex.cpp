#include <iostream>
#include "vertex.h"
#ifndef VERTEX
#define VERTEX

using namespace std;

vertex::vertex(string inputLabel){
    label = inputLabel;

}
string vertex::getLabel(){
    return label;
    
}
void vertex::setLabel(string inputLabel){
    label = inputLabel;
    
}

#endif 
