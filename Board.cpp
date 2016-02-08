#include "stdafx.h"
#include "Board.h"
#include "GameLogic.h"


Board::Board()
{
    initBoard();
}


void Board::initBoard()
{
    std::vector<char> rows(ROWS, EMPTY);
    m_board = std::vector<std::vector<char>>(COLUMNS, rows);
}


void Board::display()
{
    int rowText = 1;
    std::cout << "\n";
    std::cout << "\t  ";
    //Display The column Text
    for (int colText = 1; colText < COLUMNS - 1; colText++)
    {
        std::cout << colText << "  ";
    }
    std::cout << "\n";
    //Display the board
    for (int row = 1; row < ROWS - 1; row++)
    {
        std::cout << "\t";
        std::cout << rowText; //Display the row text
        rowText++;

        for (int col = 1; col < COLUMNS - 1; col++)
        {
            std::cout << "|" << m_board[row][col] << "|";
        }
        std::cout << "\n";
    }
}

bool Board::isMoveLegal(const int row, const int col) const
{
    std::vector<int> fullRow;
    if (m_board[row][col] == EMPTY)
    {

        if (row == ROWS - 2) //If requested move is on the bottom row
            return true;

        else
        {
            //Check to see whether or not the square underneath requested move is not empty
            int tempRow = row;
            tempRow++;
            if (getPosition(tempRow, col) != EMPTY)
                return true;

            else {
                return false;
            }

        }
    }

    else {
        return false;
    }


}

bool Board::searchForWinner(GameLogic& gameLogic, Directions direction, Board& board, char gamePiece)
{
    if (!gameLogic.isWinnerFound())
    {
        int i = 0;
        for (int row = 1; row < Board::ROWS - 1; row++)
        {
            for (int col = 1; col < Board::COLUMNS - 1; col++)
            {
                while (board.getPosition(row, col) == gamePiece && !gameLogic.isWinnerFound())
                {
                    i++;

                    if (direction == Directions::Horizontal) {
                        row++;
                    }

                    if (direction == Directions::Vertical) {
                        col++;
                    }

                    if (direction == Directions::LeftDiagonal) {
                        row++;
                        col--;
                    }

                    if (direction == Directions::RightDiagonal) {
                        row++;
                        col++;
                    }

                    if (i == GameLogic::WINNING_ROW) {
                        return true;
                    }
                }
                i = 0;
            }
        }
    }

    //If winner has already been found
    else if (gameLogic.isWinnerFound()) {
        return true;
    }

    return false;

}


bool Board::findWinner(GameLogic & gameLogic, Board & board, char gamePiece)
{
    return searchForWinner(gameLogic, Directions::Horizontal, board, gamePiece);
        searchForWinner(gameLogic, Directions::Vertical, board, gamePiece) ||
        searchForWinner(gameLogic, Directions::RightDiagonal, board, gamePiece) ||
        searchForWinner(gameLogic, Directions::LeftDiagonal, board, gamePiece);
}

void Board::clear()
{
    m_board.clear();
    initBoard();
}
