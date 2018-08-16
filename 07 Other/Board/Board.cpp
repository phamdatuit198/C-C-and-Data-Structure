/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.a
 ** Date: June 5, 2017
 ** Description: Write a function of Board class
 ***************************************************************************/

#include "Board.hpp"



/*****************************************************************************
 **
 ** Description: Constructor of board create empty board
 ** Return: no return
 **
 ****************************************************************************/


Board::Board(){
    
    //empty board
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            arrayBoard[i][j]='*';
        cout<<"\n";
    }
}



/*****************************************************************************
 **
 ** Description: check position is empty or it is not
 ** Param: pos1 is position of row
 ** Param: pos2 is position of colum
 ** Return: bool
 **
 ****************************************************************************/

bool Board::makeMove(int pos1,int pos2){
    
    if(arrayBoard[pos1][pos2] == 'X' || arrayBoard[pos1][pos2]=='O')
        return false;
    else
        return true;
}



/*****************************************************************************
 **
 ** Description: check state of board
 ** Return: value of State
 **
 ****************************************************************************/

State Board::gameState(){
    
    int winner= checkWin();
    
    if(winner == 0)
        return inProgress;
    else if(winner == 1)
        return X_Win;
    else if(winner == 2)
        return O_Win;
    else
        return isDraw;

}



/*****************************************************************************
 **
 ** Description: check who is winner or state of board
 ** Return: int
 **
 ****************************************************************************/

int Board::checkWin(){

    char key = '*';
    int winner = -1;  //nobody winner
    
    //Winner on row
    
    for (int i=0; i < 3; i++)
        if (arrayBoard [0] [i] == arrayBoard [1] [i] && arrayBoard [0] [i] == arrayBoard [2] [i] && arrayBoard [0] [i] != '*')
            key = arrayBoard [0] [i];

    //Winer on colume
    for (int i=0; i < 3; i++)
        if (arrayBoard [i] [0] == arrayBoard [i] [1] && arrayBoard [i] [0] == arrayBoard [i] [2] && arrayBoard [i] [0] != '*')
            key = arrayBoard [i] [0];
    
    
    if (arrayBoard [0] [0] == arrayBoard [1] [1] && arrayBoard [1] [1] == arrayBoard [2] [2] && arrayBoard [1] [1] != '*')
            key = arrayBoard [1] [1];
    
    if (arrayBoard [0] [2] == arrayBoard [1] [1] && arrayBoard [1] [1] == arrayBoard [2] [0] && arrayBoard [1] [1] != '*')
        
            key = arrayBoard [1] [1];
    
    if (key == 'X')
        winner = 1;         //X win
    else if (key == 'O')
        winner = 2;         // O win
    else if (isFull())
        winner = 3;         // board is full
    else
        winner =0;          //nobody winner
    
    return winner;

}



/*****************************************************************************
 **
 ** Description: check board is full or it is not
 ** Return: bool
 **
 ****************************************************************************/

bool Board::isFull(){
    
    for (int i=0; i < 3; i++ ){
        
        for (int j=0; j < 3; j++ ){
                if (arrayBoard [i] [j] == '*')
                    return false;
        }
    }
        return true;


}



/*****************************************************************************
 **
 ** Description: display current board
 ** Return: no return
 **
 ****************************************************************************/

void Board::display(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<"  "<<arrayBoard[i][j];
        cout<<"\n\n";
    }

}



/*****************************************************************************
 **
 ** Description: add position of player
 ** Return: no return
 **
 ****************************************************************************/

void Board::addBoard(int pos1,int pos2,char player){
    
    if(player=='X')
        arrayBoard[pos1][pos2] = 'X';
    else
        arrayBoard[pos1][pos2] = 'O';
}
