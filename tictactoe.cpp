#include <iostream>
#include <cstring>

using namespace std;


//declaring methods
int printBoard(char board2Print[4][4]);
int printTurn(int &turn);
int instructions();
int move (int turn, int column, int row, char(&board)[4][4]);
int getMove(char &row,char &column,char (&aConversion)[3],char (&AConversion)[3],char (&nConversion)[3],int &rowMove, int &columnMove,char(&board)[4][4]);
int switchTurn(int &turn);
int checkWin(bool &win, char (&board)[4][4],int &turn,int &Xcount, int &Ocount );
int checkTie(bool &win, char(&board)[4][4]);
int printWins(int &Xcount,int&Ocount);
int printPlayAgain();

int main(){
  //initializing variables


  int XwinCount=0;
  int OwinCount=0;
  int X = 0;
  int O = 1;
  int turn =0;
  int playerMove = 0;
  int columnMove= 0;
  int rowMove =0;
  bool win = false;
  
  turn = X;
  win = false;
  char rowInput;
  char columnInput;

  char board[4][4]= { {' ','1','2','3'},{'A',' ',' ',' '},{'B',' ',' ',' '},{'C',' ',' ',' '}};//main board where gameplay occours

  //arrays to convert the moves to integer coordinates
  char alphaConversion[3] = {'a','b','c'};
  char AlphaConversion[3] = {'A','B','C'};
  char numConversion[3] = {'1','2','3'};

  printBoard(board);//prints board
  printTurn(turn);//prints whos turn it is

  
  while(win == false){//while nobody has won the game
    getMove(rowInput,columnInput,alphaConversion,AlphaConversion,numConversion,rowMove,columnMove,board);//gets the move from the user
    move(turn, columnMove, rowMove, board);//adds it to the board
    printBoard(board);//prints the board
    checkWin(win,board,turn,XwinCount,OwinCount);//checks for wins
    checkTie(win,board);//checks for ties
    printWins(XwinCount,OwinCount);//prints the win count
    switchTurn(turn);//switches turn
    if(win == true){//if someone wins the game
      printPlayAgain();//asks if they want to play again
    }
  }
  return 0;
}
//end main



int getMove(char &row,char &column,char (&aConversion)[3],char (&AConversion)[3],char (&nConversion)[3],int &rowMove, int &columnMove, char (&board)[4][4]){//gets the move from the user and check to make sure it is valid before converting it to integer coordinates
  //outputs initial move instructions
  cout<< "Which row(A,B,C) & Column(1,2,3) would you like to move too"<<endl;
  cin>>row;
  cin>>column;
  while((column!= '1' && column!='2'&&column!='3')||(row!='A'&&row!='B'&&row!='C')){//if move was invalid asks again
     cout<<"Invalid Move Please Try Again, enter your move as \" Row Column\" no spaces"<<endl;
     cout<< "Which row(A,B,C) & Column(1,2,3) would you like to move too"<<endl;
     cin>>row;
     cin>>column;
   }
  
  cout<< row<<" , "<<column<<endl;//outputs your move
  for(int i=0; i<3; i++){//converts valid move to coordinates that can be checked in board
      if(row == aConversion[i] | row == AConversion[i]){
        rowMove = i+1;
      }
      if(column == nConversion[i]){
        columnMove=i+1;
      }
    }
  if(board[rowMove][columnMove] == 'X'||board[rowMove][columnMove] == 'O'){//checks to see if move was already made in the spot of the move inputted
   cout<<"a move has already been made to this lcoation please try again"<<endl;
   getMove(row,column,aConversion,AConversion,nConversion,rowMove,columnMove,board);//if it has reasks the user for a move
  
 }
  
  return 0;
}
int switchTurn(int &turn){//switches turn between X and O at end of turn
  int x=0;//X
  int o=1;//O
  if(turn == x){//if turn is X make it O
    turn = o;
  }
  else if(turn == o){//if turn is O make it X
    turn=x;
  }
  return 0; 
}

int move (int turn, int column, int row, char (&board)[4][4]){//takes the converted move coordinates from getMove and prints the move on the board
  int X = 0;
  int O = 1;
  if(turn == X){
    board[row][column]= 'X';
  }
  if(turn == O){
    board[row][column] = 'O';
  }
  cout<<"turn: "<<turn<<endl;
  return 0;
}    

int printTurn(int &turn){//print whos turn it is
  int X = 0;
  int O = 1;
  if(turn == X){
    cout<<"Its X's Move"<<endl;
  }
  else if(turn == O){
    cout<<"Its O's Move"<<endl;
  }

  return 0;
}
int printBoard(char board2Print[4][4]){//prints the board

for(int i=0; i<4; i++){
     cout<<endl;
     for(int j =0; j<4;j++){
       cout<<' '<<board2Print[i][j]<<' ';
     }
    }
 cout<<endl;
  return 0;
}
int instructions(){//prints initial instructioms
  cout<<"Welcome to Tic-Tac-Toe"<<endl;
  cout<<"You will enter your move as a row(A,B or C) and then as a column(1,2, or 3)"<<endl;

  return 0;
}
int checkTie(bool&win,char(&board)[4][4]){//checks for tie
  int count = 0;
  for(int i=1; i<4;i++){
    for(int j=1;j<4;j++){
      if(board[i][j] == 'X' || board[i][j] =='O'){
	count++;
    }
  }
 }
  if(count == 9){//if board is full
    win = true;//start game over sequence
      cout<<"its a tie!"<<endl;
    }
  
  return 0;
}
int checkWin(bool &win,char (&board)[4][4],int &turn,int &Xcount, int &Ocount ){//checks for win
  //checks rows and columns for win
  if((board[1][1] == 'O' && board[1][2] == 'O' && board[1][3] == 'O')|(board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X')){
      win = true;
    }
    else if((board[2][1] == 'O' && board[2][2] == 'O' && board[2][3] == 'O')|(board[2][1] == 'X' \
&& board[2][2] == 'X' && board[2][3] == 'X')){
      win = true;
    }
   else if((board[3][1] == 'O' && board[3][2] == 'O' && board[3][3] == 'O')|(board[3][1] == 'X' \
&& board[3][2] == 'X' && board[3][3] == 'X')){
      win = true;
    }
    else if((board[1][1] == 'O' && board[2][1] == 'O' && board[3][1] == 'O')|(board[1][1] == 'X' \
&& board[2][1] == 'X' && board[3][1] == 'X')){
      win = true;
    }
    else if((board[1][2] == 'O' && board[2][2] == 'O' && board[3][2] == 'O')|(board[1][2] == 'X' \
&& board[2][2] == 'X' && board[3][2] == 'X')){
      win = true;
    }
    else if((board[1][3] == 'O' && board[2][3] == 'O' && board[3][3] == 'O')|(board[1][3] == 'X' \
&& board[2][3] == 'X' && board[3][3] == 'X')){
      win = true;
    }
    //checks diaganols for win

    else if((board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O')|(board[1][1] == 'X' \
&& board[2][2] == 'X' && board[3][3] == 'X')){
      win = true;
    }
    else  if((board[3][1] == 'O' && board[2][2] == 'O' && board[1][3] == 'O')|(board[3][1] == 'X' \
&& board[2][2] == 'X' && board[1][3] == 'X')){
      win = true;
    }

  //cout message
  int X = 0;
  int O = 1;
  if(win == true){//if you won
    if(turn == X){//if X won
      Xcount++;//adds win
     }
    else if(turn == O){//if O won
      Ocount++;//adds win
     }
      cout<<"you won!"<<endl;
    }
     return 0;
}

int printWins(int &Xcount,int&Ocount){//prints the wins for each player

  cout<< "X Wins: "<<Xcount<<"    "<<"O Wins: "<< Ocount<<endl;
  return 0;
}
int printPlayAgain(){//asks user if they want to play again

  char input = 'A';
  //asks the question
  cout<<"do you want to play again?"<<endl;
  cout<<"type Y if yes and N if no"<<endl;
  cin>>input;
  if(input == 'Y'){//if user inputs Y runs main again

    main();
  }
  else if(input == 'N'){//if user inputs N ends program
    cout<<"Okay, goodbye"<<endl;
  }
  else{//otherwise asks the question again
    cout<<"That was not a valid response please try again"<<endl;
    printPlayAgain();
  }
  return 0;
}

