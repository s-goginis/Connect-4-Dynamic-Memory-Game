//Author: Shreya Gogini
//player.cpp
//Desc: the player.cpp file that runs the methods relating to player
#include <iostream>
//including the header file to access the methods
#include "player.h"

using namespace std;

//desc : starts the game with a welcome and prompts the user to enter dimensions
//pre : None
//post : None
void player::start()
{
    cout << "************************************\n"
       << "*    Welcome to Connect-4-Game     *\n"
       << "************************************\n";
    cout <<"Enter the starting dimensions of the board (4x4 or bigger)" << endl;
  
}

//desc : gets which player's turn this round is
//pre : integer 'num' must be non-negative and greater than 0
//post : returns an integer to the function call
int player::get_turn(int num)
{
  int turn;
  if(num %2 == 0){
    turn = 2;
  }
  else if(num %2 != 0){
    turn = 1;
  }
    return turn;
}

//desc : allows the player to input the column and runs the player's turn
//pre : 'grid' must be initialized properly, 
//       width and height must be greater than 4, round must be non-negative
//post : returns the updated grid with no out-of-bounds placements in memory
char** player::player_turn(char **grid, int width, int height, int round)
{
    int choice = 0;
    int turn;
    //uses the round number to get which player's turn it is
    turn = get_turn(round);
  //Gets column choice from  player
  cout << "Player " << turn << ", select a column number [0-" << width-1 << "] " << endl;
  cin >> choice;
  //checking and eliminating out of bounds
  while(!(choice >= 0 && choice <= width-1)){
    cout << "Invalid choice, choose again: " << endl;
    cin >> choice;
  }
  
  
  bool empty = true;
  //Makes user pick again if the column is full
  while((grid[0][choice] == 'X' || grid[0][choice] == 'O')){
    cout << "Column is full. Enter another column:";
    cin >> choice;
  }

  //Populates the board with the player's token
  while(empty == true){
	if(grid[height-1][choice] == ' '){//Checks for placement
      if(turn == 1){ 
        grid[height - 1][choice] = 'X';
      }
      else if(turn == 2){
        grid[height - 1][choice] = 'O';
      }
      empty = false;
	}
	else if (grid[height-1][choice]!=' '){//Finds empty spot in column
      int i = 2;
      while(empty == true && i<=height){
        if(grid[height-i][choice] == ' '){
          if(turn == 1){
            grid[height-i][choice] = 'X';
          }
          else if(turn == 2){
            grid[height-i][choice] = 'O';
          }
          empty = false;
        }
        i++;
      }
    }
  }
  //returns the updated game board
  return grid;
}

//desc : called after each round to check for winner
//pre : 'grid' must be initialized properly, 
//       width and height must be greater than 4, num must be non-negative
//post : returns bool value based on tests conducted in function
bool player :: check_winner(char **grid, int width, int height, int num){
   bool winner = false;
   char turn = ' ';
   int round = 0; 
   //getting the round (player for this round)
   round = get_turn(num);
   if(round == 1){
    turn = 'X';
   }
   else if(round == 2){
    turn = 'O';
   }
  //Horizontal check
  for(int i = 0; i < height-3 && winner == false; i ++){
    //makes sure to stay within the bounds of the board
    for(int j = 0; j < width && winner == false; j++){
      if(grid[i][j] == turn && grid[i+1][j] == turn
         && grid[i+2][j] == turn && grid[i+3][j] == turn){
        winner = true;
      }
    }
  }
  //vertical check
  for(int m = 0; m < height && winner == false; m ++){
    for(int n = 0; n < width-3 && winner == false; n++){
      if(grid [m][n] == turn && grid[m][n+1] == turn
         && grid[m][n+2] == turn && grid[m][n+3] == turn){
        winner = true;
      }
    }
  }
  //returns true or false to either continue or end the game
  return winner;
}
