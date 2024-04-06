//Author : Shreya Gogini
//board.h
//Description: header file containing the class declaration and methods
#include <iostream>

class board{
    public:
    char ** newBoard(int, int);
    void printBoard(int, int, char**);
  
    void deleteBoard(char **, int);

};
