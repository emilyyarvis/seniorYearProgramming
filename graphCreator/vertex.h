#include<iostream>
//#ifndef VERTEX
//#define VERTEX
using namespace std;

class vertex{

public:
    vertex(string inputLabel);
    string getLabel();
    void setLabel(string inputLabel);

private:
    string label;
};
//#endif
