//
//  mainFunctions.cpp
//  tictactoe4x4
//
//  Created by Evgeny Tolmachev on 29/06/2021.
//

#include <iostream>


//
//#include <string>

struct userInp{
    char Char;
    int Row;
    int Col;
};

void getUserNames(std::string &userX, std::string &userY)
{//get the user names
    std::cout<< "Name of user to be 'x' :";
    std::cin >>userX;
    std::cout<< "Name of user to be 'o' :";
    std::cin >>userY;
}

userInp getUserInp(char xo){
    userInp user;
    user.Char = xo;
    std::cout << "Enter row number (0-3) to place "<< xo << std::endl;
    std::cin>> user.Row;
    std::cout<< "Enter column number (0-3) to place " << xo << " : \n" ;
    std::cin>> user.Col;
    return user;
}
