/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.a
 ** Date: June 5, 2017
 ** Description: Write a function of Board class
 ***************************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

enum State { X_Win,O_Win,isDraw,inProgress};    //State of game, we have four

class Board{
    
private:
    
    char arrayBoard[3][3];              //array of board
    
public:
    Board();                            //Constructor of class
    bool makeMove(int,int);             //function determine player can move to position
    State gameState();                  //function is defined state of game
    void display();                     //display board of game
    void addBoard(int,int,char);        //add to a board
    int checkWin();                     //check who is win
    bool isFull();                      //check board full
};

#endif 
