#pragma once

#include <iostream>
#include <vector>

enum class Directions
{
    Horizontal,
    Vertical,
    RightDiagonal,
    LeftDiagonal
};

class GameLogic;
class Board
{
private:
    std::vector<std::vector<char>> m_board;

    void initBoard();

    bool searchForWinner(GameLogic& gameLogic, Directions direction, Board& board, char gamePiece);

public:
    Board();
    static const int ROWS = 9;
    static const int COLUMNS = 9;

    static const char X = 'X';
    static const char O = 'O';
    static const char EMPTY = ' ';

    char getPosition(int row, int col) const { return m_board[row][col]; }
    void addGamePiece(const int row, const int col, const char gamePiece) { m_board[row][col] = gamePiece; }

    bool isMoveLegal(const int row, const int col) const;

    void display();
    void clear();
    bool findWinner(GameLogic& gameLogic, Board& board, char gamePiece);
};
