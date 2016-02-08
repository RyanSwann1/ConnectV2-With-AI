#pragma once
#include "Player.h"

#include <iostream>

class humanPlayer :
    public Player
{
private:
    int getPosition(std::string direction, int size);
public:
    humanPlayer();
    ~humanPlayer();

    void takeTurn(Board& board);

};
