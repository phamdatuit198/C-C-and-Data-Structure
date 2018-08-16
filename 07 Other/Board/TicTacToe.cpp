/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.a
 ** Date: June 5, 2017
 ** Description: Write a function of TicTacToe class
 ***************************************************************************/

#include "TicTacToe.hpp"



/*****************************************************************************
 **
 ** Description: constructor use for enter value of player data member
 ** Param: input is a character of player
 ** Return: no return
 **
 ****************************************************************************/



TicTacToe::TicTacToe(char input){
    player = input;
}



/*****************************************************************************
 **
 ** Description: Start game TicTacToe. function is called at main function
 ** Return: no return
 **
 ****************************************************************************/


void TicTacToe::startGame(){
    
    bool endGame = false;
    bool recall = false;
    int pos[2];
    char *pointer;
   
    char std[10];
    int i=0;
    
    do{
        do{
            recall = false;
            i=0;
            cout<<"Player "<<player<<": Please enter your move. \n";
            cin.ignore(10,'\n');
            cin.get(std,10);
            
            pointer = strtok(std," ");
            
            while(pointer!=NULL){
                
                if(isdigit(*pointer)){
                    
                    pos[i] = atof(pointer);
                }else
                    recall = true;
                
                pointer = strtok(NULL," ");
                i++;
                
            }
            
            //check value can't over 2
            if(pos[0]<3 && pos[1]<3){
                
                //check board
                if(!myBoard.makeMove(pos[0], pos[1])){
                    recall = true;
                    cout<<"That square is already taken.\n";
                }else{
                    recall = false;
                    //add to board
                    myBoard.addBoard(pos[0], pos[1],player);
                }
            }else
                recall = true;
            
        }while(recall);
        
        //display board after play
        myBoard.display();
        
        //check win
        switch (myBoard.gameState()) {
            case X_Win:
                cout<<"X is win! \n";
                endGame = true;
                break;
            case O_Win:
                cout<<"O is win! \n";
                endGame = true;
                break;
            case isDraw:
                cout<<"The game is a draw! \n";
                endGame = true;
                break;
            case inProgress:
                cout<<"The game is still in progress! \n";
                endGame = false;
                break;
            default:
                break;
        }
        //next player
        if(player == 'X')
            setPlayer('O');
        else
            setPlayer('X');

    }while(!endGame);
}



/*****************************************************************************
 **
 ** Description: get player data member
 ** Return: player data member
 **
 ****************************************************************************/


char TicTacToe::getPlayer(){
    return player;
}


/*****************************************************************************
 **
 ** Description: set player data member
 ** param: to_add is a character of player
 ** Return: no return
 **
 ****************************************************************************/

void TicTacToe::setPlayer(char to_add){
    player = to_add;
}


/*****************************************************************************
 **
 ** Description: Main function
 ** Return: 1
 **
 ****************************************************************************/

int main() {
    
    char player;
    
    cout<<"Enter player play first: ";
    cin>>player;
    TicTacToe myTic(player);
    myTic.startGame();
    
    
    return 0;
}

