//
//  main.cpp
//  tictactoe4x4
//
//  Created by Evgeny Tolmachev on 29/06/2021.
//

#include <iostream>
#include <string>
#include "mainClasses.hpp"
#include "mainFunctions.hpp"


static bool checkWinner(bool fin, char winner) {
    if(winner != 't'){
        std::cout << "The winner is "<< winner << std::endl;
        return true;
    } else if(winner == 't' and fin == true) {
        std::cout << "It's a tie!\n";
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    Board ttt;
    stats stats = ttt.boardSearch();
    
    userInp user;
    
    char xo = 'x';
    bool fin = false;
    char winner = 't';
    bool flag = false;
    
    while(1){
        ttt.printBoard();
        xo = 'x';
        user = getUserInp(xo);
        ttt.placeChar(user.Char, user.Row, user.Col);
        stats = ttt.boardSearch();
        fin = ttt.gameFinished(stats);
        winner = ttt.isWinner();
        flag = checkWinner(fin, winner);
        if(flag == true){
            break;
        }
        
        ttt.printBoard();
        xo = 'o';
        
        user = getUserInp(xo);
        ttt.placeChar(user.Char, user.Row, user.Col);
        stats = ttt.boardSearch();
        fin = ttt.gameFinished(stats);
        winner = ttt.isWinner();
        flag = checkWinner(fin, winner);
        
        if(flag == true){
            break;
        }
        }
       
    
    
    return 0;
}
