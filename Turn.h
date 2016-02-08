#pragma once

class Player;
class Board;
class Turn
{
private:
    char m_turn = ' ';

    void init();

public:
    Turn();
    ~Turn();

    void decideFirstTurn(Player& player1, Player& player2);
    void changeTurn(char turn);
    char getTurn() { return m_turn; }
    void announceTurn(std::string player) { std::cout << player << "'s turn.\n"; }
    void setFirstTurn() { m_turn = Board::X; }
};
