//
//  mainClasses.cpp
//  tictactoe4x4
//
//  Created by Evgeny Tolmachev on 29/06/2021.
///Users/evgenytolmachev/Documents/Linmodr/cplusplus/tictactoe4x4/tictactoe4x4/mainClasses.cpp

#include <iostream>
#include <vector>

const int ROWS = 4;
const int COLUMNS = 4;

struct stats{
    int x_;
    int o_;
    int blank_;
};

class Board{
private:
    char boardPositions[ROWS][COLUMNS];
public:
    stats boardSearch(){
        stats stats;
        char xoblank;
        for(int i=0; i < ROWS; i++){
            for(int j=0; j < COLUMNS; j++){
                xoblank = boardPositions[i][j];
                switch(xoblank){
                    case 'x':
                        stats.x_ +=1;
                    case 'o':
                        stats.o_ +=1;
                    case '-':
                        stats.blank_ +=1;
                }
            }
        }
        return stats;
    }
    
    Board(){
        for(int i=0; i < ROWS; i++){
            for(int j=0; j < COLUMNS; j++){
                boardPositions[i][j] = '-';
            }
        }
    }
    
    void printBoard(){
        for(int i=0; i < ROWS; i++){
            for(int j=0; j < COLUMNS; j++){
                std::cout << boardPositions[i][j];
            }
            std::cout << std::endl;
        }
    }
    
    bool placeChar(char xo, int row, int col){
        if(boardPositions[row][col] == '-'){
            if(xo == 'x'){
                boardPositions[row][col] = 'x';
                return true;
            }
            else if (xo == 'o'){
                boardPositions[row][col] = 'o';
                return true;
            }
        }
        std::cout << "Position taken" << std::endl;
        return false;
    }
    
    bool gameFinished(stats stats){
        if(stats.x_ == 8 and stats.o_ == 8){
            return true;
        } else {
            return false;
        }
    }
    
    char isWinner(){
        int xScore= 0;
        int oScore= 0;
//        loop to find a winner in rows;
        for(int i=0; i < ROWS; i++){
            for(int j=0; j < COLUMNS; j++){
                char xo = boardPositions[i][j];
                if(xo == 'x'){
                    xScore += 1;
                }
                else if(xo == 'o'){
                    oScore += 1;
                }
            }
            if(xScore == 4){
                return 'x';
            }
            else if(oScore == 4){
                return 'o';
            }
            xScore = 0;
            oScore = 0;
        }
//        loop to find winner in columns
        for(int i=0; i < ROWS; i++){
            for(int j=0; j < COLUMNS; j++){
                char xo = boardPositions[j][i];
                if(xo == 'x'){
                    xScore += 1;
                }
                else if(xo == 'o'){
                    oScore += 1;
                }
            }
            if(xScore == 4){
                return 'x';
            }
            else if(oScore == 4){
                return 'o';
            }
            xScore = 0;
            oScore = 0;
        }
//        loop to find winner in left to right diagonal 1,1 2,2 3,3
        int j = 0;
        for(int i=0; i < ROWS; i++){
            char xo = boardPositions[i][j];
            if(xo == 'x'){
                xScore += 1;
            }
            else if(xo == 'o'){
                oScore += 1;
            }
            if(xScore == 4){
                return 'x';
            }
            else if(oScore == 4){
                return 'o';
            }
            j += 1;
        }
        
//loop to find winner in right left diagonal;
        j = 0;
        xScore = 0;
        oScore = 0;
        for(int i=ROWS; i > 0; i--){
            char xo = boardPositions[i][j];
            if(xo == 'x'){
                xScore += 1;
            }
            else if(xo == 'o'){
                oScore += 1;
            }
            if(xScore == 4){
                return 'x';
            }
            else if(oScore == 4){
                return 'o';
            }
            j += 1;
        }
//        return tie if nothing found;
        return 't';
    }
};
