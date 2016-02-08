#include "stdafx.h"
#include "Turn.h"
#include "Board.h"
#include "Player.h"


Turn::Turn()
{
    init();
}


Turn::~Turn()
{
}


void Turn::init()
{
    m_turn = Board::X;
}


void Turn::changeTurn(char turn)
{
    if (turn == Board::X) {
        m_turn = Board::O;
    }
    else {
        m_turn = Board::X;
    }
}


void Turn::decideFirstTurn(Player& player1, Player& player2)
{
    char responce;
    bool decided = false;
    while (!decided)
    {
        std::cout << "Would you like to go first? 'y' - Yes. 'n' - No.";
        std::cin >> responce;

        if (responce == 'y' || responce == 'n') {
            decided = true;
        }
    }

    if (responce == 'y') {
        player1.setGamePiece(Board::X);
        player2.setGamePiece(Board::O);
    }
    else {
        player2.setGamePiece(Board::X);
        player1.setGamePiece(Board::O);
    }

}
