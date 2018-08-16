/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.a
 ** Date: June 5, 2017
 ** Description: Write a function of TicTacToe class
 ***************************************************************************/

#ifndef TicTacToe_hpp
#define TicTacToe_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include "Board.hpp"

using namespace std;

class TicTacToe{

private:
    //Data member
    
    Board myBoard;              //Board of game
    char player;                //Player will play
    
public:
    TicTacToe(char);            //Constructor of class
    void startGame();           //Function is start game
    void setPlayer(char);       //set value for player data member
    char getPlayer();           //get value player data member
};
#endif 
