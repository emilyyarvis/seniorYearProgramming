#include <iostream>
#include <cstring>

using namespace std;


int main(){

  //initializes variables
  int n = 200000;
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  char str[n];
  char str2[n];
  int count = 0;
  int length = 0;
  
  //gets the input from the user
  cout << "type in a word"<<endl;
  cin.get(str,n);
  cin.get();
  cout <<"bruh "<< str<<endl;
  cout<<"n: " <<n<<endl;
  
  
   for(int i =0; i<n; i++){
    
     if(str[i] == '\0'){
       cout<<"found"<<endl;
       length = i;
       break;
     } 
    }
   cout<< "Length: " << length <<endl;

   //making the opposite string

   str2[length] = str[length];
    count = length -1;
   for(int i=0; i<=(length-1);i++){
     str2[count] = str[i];
     count--;
   }
   
   //debugging////////////////////////
   for(int i=0; i<=length; i++){    //
     cout<< "bish " <<str[i]<<endl; //
   }                                //
   for(int i =0; i<=length; i++){   //
     cout<<"bro " << str2[i]<<endl; //
   }                                //
   for(int i=length;i>=0; i--){     //
     cout<<"shoot "<< str2[i]<<endl;//
   }                                //
   ///////////////////////////////////
   
  
  cout <<"Answer: "<< str2<<endl;

  //comparing the strings
  if(strcmp(str,str2) == 0){
    cout<< "GG"<<endl;
  }
  else{
    cout<<"double GG"<<endl;
  }


  if('A' == 'a'){
    cout<<"ooh instretsin"<<endl;
  }
  else if('A'!='a'){
    cout<<"darn"<<endl;
  }
  
  return 0;
}
