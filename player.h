//Author : Shreya Gogini
//player.h
//Description: header file containing the class declaration and methods
#include <iostream>

class player{
    public:
    void start();
    int get_turn(int);
    char** player_turn(char**, int, int, int);
    bool check_winner(char**, int, int, int);

};
