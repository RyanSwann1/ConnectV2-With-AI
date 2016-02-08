#include "stdafx.h"
#include "humanPlayer.h"
#include "Board.h"


humanPlayer::humanPlayer()
{
    std::cout << "Human activated.\n";
}


humanPlayer::~humanPlayer()
{
}



void humanPlayer::takeTurn(Board & board)
{
    //Get spawn position
    bool moveComplete = false;

    while (!moveComplete) 
    {
        m_row = getPosition("Row", Board::ROWS);
        m_col = getPosition("Column", Board::COLUMNS);

        if (board.isMoveLegal(m_row, m_col)) 
        {
            board.addGamePiece(m_row, m_col, m_gamePiece);
            moveComplete = true;
        }

        else {
            std::cout << "Move is not allowed.";
        }
    }

}

int humanPlayer::getPosition(std::string direction, int size)
{
    bool positionAllowed = false;
    int pos = 0;
    std::cout << "Enter " << direction << ".\n";
    while (!positionAllowed) 
    {
        std::cin >> pos;

        if (pos > 0 && pos < size - 1) {
            positionAllowed = true;
            std::cout << "Enter " << direction << ".\n";
        }
    }
    return pos;
}
