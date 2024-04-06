//Author : Shreya Gogini
//board.cpp
//Description: board.cpp file that runs the methods relating to the board
#include <iostream>
//including the header file to access methods
#include "board.h"

using namespace std;

//desc : gets the dimensions of the board and creates a dynamic 2d array
//pre : width and height must be non-negative
//post : returns a dynamically allocated 2d array 
//       with exactly height*width elements
char** board::newBoard(int width, int height)
{
    // dynamic allocation of a 2d array
    char **grid = new char *[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
    }
    // filling with a designated character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = ' ';
        }
    }
    // returns the new board at the end of the function
    return grid;
}

//desc : prints the array on the screen so users can interact
//pre : grid has to be allocated correctly, and width and height must be positive
//post : only print elements within bounds of width and height
void board ::printBoard(int width, int height, char ** grid )
{ 
  // Print the Connect4 board
   for (int r = 0; r < height; r++){
      // Draw dashed line
      cout << "+";
      for (int c = 0; c < width; c++)
         cout << "---+";
      cout << "\n";
      // Draw board contents
      cout << "| ";
      for (int c = 0; c < width; c++)
         cout << grid[r][c] << " | ";
      cout << "\n";
    }
   // Draw dashed line
   cout << "+";
   for (int c = 0; c < width; c++)
      cout << "---+";
   cout << "\n";
}

//desc : deallocates the dynamic array
//pre : grid should be a valid, dynamically allocated array in memory
//post : deallocates the array 
void board :: deleteBoard(char ** grid, int height){
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}
