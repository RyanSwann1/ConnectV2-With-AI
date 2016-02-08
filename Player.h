#pragma once
#include <string>

class Board;
class GameLogic;
class Player
{
protected:
    int m_row = 0;
    int m_col = 0;
    std::string m_name;
    char m_gamePiece = ' ';

public:
    Player();

    virtual void takeTurn(Board& board) = 0;

    //Set
    void setRow(const int row) { m_row = row; }
    void setCol(const int col) { m_col = col; }
    void setName(std::string name) { m_name = name; }   
    void setGamePiece(const char gamePiece) { m_gamePiece = gamePiece; }

    //Get
    char getGamePiece() const { return m_gamePiece; }
    int getRow() const { return m_row; }
    int getCol() const { return m_col; }
    std::string getName() { return m_name; }

};
