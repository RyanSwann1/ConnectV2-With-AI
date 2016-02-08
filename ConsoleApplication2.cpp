// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "GameLogic.h"
#include "Board.h"
#include "Turn.h"

#include <iostream>
#include <ctime>

bool isComputerInPlay()
{
    char choice = ' ';
    bool decided = false;
    while (!decided)
    {
        std::cout << "Would you like to play against a computer? 'y' - Yes. 'n' - No.";
        std::cin >> choice;

        if (choice == 'y' || choice == 'n') {
            decided = true;
        }
    }

    if (choice == 'y') {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Seed random. Only using on lite projects

    GameLogic gameLogic;
    Board board;
    Turn turn;

    Player* player1 = new humanPlayer;
    Player* player2 = nullptr;

    gameLogic.setComputerToPlay(isComputerInPlay());

    if(gameLogic.isComputerInplay())
    {
        player2 = new computerPlayer;
    }
    else
    {
        player2 = new humanPlayer;
    }

    //Begin game
    gameLogic.game(gameLogic, *player1, *player2, board, turn);

    return 0;
}
