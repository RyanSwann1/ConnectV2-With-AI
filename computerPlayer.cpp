#include "stdafx.h"
#include "computerPlayer.h"
#include "Board.h"
#include "GameLogic.h"


computerPlayer::computerPlayer()
{
    std::cout << "Computer activated.\n";
}


void computerPlayer::takeTurn(Board & board)
{
    bool moveComplete = false;
    while (!moveComplete)
    {
        getPosition(board);

        int spawnPos = getRandomPosition();

        m_row = m_rowPositions[spawnPos];
        m_col = m_colPositions[spawnPos];

        moveComplete = board.isMoveLegal(m_row, m_col);
    }

    board.addGamePiece(m_row, m_col, getGamePiece());

    //Reset all
    m_availableMoves = 0;
    m_rowPositions.clear();
    m_colPositions.clear();
}


void computerPlayer::getPosition(Board& board)
{
    for (int col = 1; col < Board::COLUMNS - 1; col++)
    {
        for (int row = Board::ROWS - 2; row >= 1; row--)
        {
            if (board.getPosition(row, col) == Board::EMPTY)
            {
                m_rowPositions.push_back(row);
                m_colPositions.push_back(col);
                m_availableMoves++;
                break; //Go to next column
            }
        }
    }
}

int computerPlayer::getRandomPosition()
{
    int randNumb = rand() % m_availableMoves;
    return randNumb;
}
