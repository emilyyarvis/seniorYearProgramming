#include <iostream>
#include <cstring>

using namespace std;


int main(){

  //initializes variables
  int n = 80;//max charecters that can be checked
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";//regular alphabet
  char capsAlphabet[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//caps alphabet
  char initialStr[n];
  char str[n];
  char str2[n];
  int count = 0;
  int length = 0;
  int trueLength = 0;
  int track =0;
  
  //gets the input from the user
  cout << "type in a word"<<endl;
  cin.get(initialStr,n);//calls initialStr this inputted value
  cin.get();
  
  
   for(int i =0; i<n; i++){
     if(initialStr[i] == '\0'){//finds the real length of the char string
       cout<<"found"<<endl;
       length = i;//sets it as length
       break;
     } 
    }

   //converts all charecters to lettercase & removes spaces and punctuation
   for(int i =0; i<length;i++){//go through the whole input stirng
     for(int j = 0; j<26; j++){//goes through the letters in the alphabet
       if(initialStr[i] == alphabet[j]){//replaces when it matches
	 str[track] = alphabet[j];
	 track++;//only adds when theres a charecter so removes spaces & punctuation
       }
       else if(initialStr[i] == capsAlphabet[j]){//goes through and matches capital letters if needed
	 str[track] = alphabet[j];
	 track++;//skips spaces and punctuation
       }
      
     }
     
   }
   trueLength = track;//resets length to the length of the string without the spaces and punctuation
   str[trueLength] = '\0';//adds null charecter to the end of converted string

   
   
   //making the opposite string

   str2[trueLength] = str[trueLength];//adds null charceter to the end of the opposite string
    count = trueLength -1;
    for(int i=0; i<=(trueLength-1);i++){//goes through the string and puts charceters in opposite order into new string
     str2[count] = str[i];
     count--;
   }
  
  cout <<"Answer: "<< str2<<endl;

  //comparing the strings
  if(strcmp(str,str2) == 0){
    cout<< "This is a palindrome!"<<endl;
  }
  else{
    cout<<"This is not a palindrome"<<endl;
  }
  return 0;
}
