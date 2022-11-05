#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student{//creates student struct
  char firstName[10];
  char lastName[10];
  int id;
  float GPA;
};
//function intializers
int add(int &i,vector<student> &stu);
int print(int &i,vector<student> &stu);
int deleter(int &count,vector<student> &stu);

int main(){

  //initializes variables
  vector<student>stu;
  int i=-1;
  string input;
  bool loop = true;

  
  while(loop == true){//while the loop is true takes input from the user
    cin>>input;
	  
    if(input == "ADD"){//adds a student to the vector
      add(i,stu);
    }
    else if(input == "PRINT"){//prints the list of students
       print(i,stu);                                         
    }
    else if(input == "DELETE"){//deletes student
      deleter(i,stu);
    }
    else if(input == "QUIT"){//quits game and exist loop
      cout<<"okay good bye"<<endl;
      loop = false;
    }
    else{//if input is not an option, asks for input again
      cout<<"input is not acceptable"<<endl;
    }
  }
  return 0;
}

int add(int &i,vector<student> &stu){//adds a student to the list
  i=i+1;//increases total running count of students
  stu.push_back(student());//adds a new student to the vector
  //takes in info and adds it to the new student we just created
   cout << "Student " << i + 1 << endl;
   cout<<"enter first name"<<endl;
   cin>>stu[i].firstName;
   cout<<"enter last name"<<endl;
   cin>>stu[i].lastName;
   cout<<"enter id"<<endl;
   cin>>stu[i].id;
   cout<<"enter GPA"<<endl;
   cin>>stu[i].GPA;
  return 0;
}

int print(int &count, vector<student> &stu){//prints the students in the list
  for(int i=0; i<count+1; i++){//for every stduent in the list, rpints all the info
     cout<<i<<endl;
     cout<< "first Name: " << stu[i].firstName<<endl;
     cout<< "last Name: " << stu[i].lastName<<endl;
     cout<< "id: " << stu[i].id<<endl;
     cout.setf(ios::showpoint);//sets it to round to _.00
     cout.precision(3);
     cout<< "GPA: " << stu[i].GPA<<endl;
  }
  return 0;
}

int deleter(int &count,vector<student> &stu){//deletes student from the list

  //intialzies needed variables
  int input=0;
  int toDelete=0;
  //gets the student to be deleted from the user
  cout<<"Enter the Student ID you want to delete"<<endl;
  cin>>input;
  for(int i =0; i<count; i++){//walks through the list of students
    if(stu[i].id == input){//if you find the id in the list, sets it to be deleted
      toDelete = i;
    }
  }
    stu.erase(stu.begin()+toDelete+1);//deletes it
    count=count-1;//adjusts count
  
  
  return 0;
}
