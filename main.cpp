//Author: Shreya Gogini
//p3.cpp
//Description: Runs a two player connect4 game using classes and header files

#include <iostream>

//Including both header files to connect with the classes
#include "board.h"
#include "player.h"


using namespace std;

//desc : runs the connect4 game until user wishes to stop
//pre : None
//post : None, aside from description
int main(){
    int width = 0;
    int height = 0;
    char **grid;
    string input;
    
    //variables for each player
    char player1 = 'X';
    char player2 = 'O';
    
    //checking for replay or not
    string replay = "y";   

    //starting the game with a welcome to the players
    player().start();
    //getting the dimensions of the board
    cin >> width;
    cin >> height;

    //making sure the dimensions are within the bounds
    while((width < 4 || 4 > height)){
        cout << "Invalid choice, choose again: " << endl;
        cin >> width;
        cin >> height;
    }
    
    //creating a new board for the game and printing it out on the screen
    grid = board().newBoard(width, height);
    board().printBoard(width, height, grid);
    
    //while the player still wants to play the game, the code will run
    while(replay == "y"){
        //keeping track of the rounds 
        int round = 0;
        //keeping track of whether there is a winner in order to end the game
        bool winner = false;
        //running the game once before asking to replay
        do{
            round ++;
            //getting the updates on the board every round and printing it
            grid = player().player_turn(grid, width, height, round);
            board().printBoard(width, height, grid);
            //checking for a winner after every round and ending the run if there is one
            winner = player().check_winner(grid, width, height, round);
        //this loop will run until there is a winner or the board is full
        }while(round < width*height && winner == false);

        //if the board is full, declare the game to end in a draw
        if(round == width*height && winner == false){
            cout << "The game has ended in a draw. \n";
        }

        //based on the round that the game ended, either player 1 or 2 will win
        if(round %2 != 0){
            cout << "Player " << player1 << " wins! \n";
        }
        else if(round %2 == 0 && round != width * height){ 
         cout << "Player " << player2 << " wins! \n";
        }

        //prompts the user for a replay
        cout << "Play again? (y/n)" << endl;
        cout << "> ";
        cin >> replay;
        //restarts the game with new dimensions provided by user
        if(replay == "y"){
            cout << "Enter dimensions (4x4 or higher):" << endl;
            cin >> width >> height;
            while((width < 4 || 4 > height)){
                cout << "Invalid choice, choose again: " << endl;
                cin >> width;
                cin >> height;
            }
            grid = board().newBoard(width, height);
        
        }
        
    }
    //deallocating the array pointed to by grid 
    board().deleteBoard(grid, height);
    return 0;
}
