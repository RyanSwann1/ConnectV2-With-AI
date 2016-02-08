#pragma once
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>




class GameLogic;
class Board;
class computerPlayer :
    public Player
{
private:
    //Stores all possible positons for computer to spawn on
    std::vector<int> m_rowPositions;
    std::vector<int> m_colPositions;
    int m_availableMoves = 0;

    void getPosition(Board& board);
    int getRandomPosition();

public:
    computerPlayer();

    void takeTurn(Board& board);


};
