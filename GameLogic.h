#pragma once

class Turn;
class Player;
class Board;
class computerPlayer;
class GameLogic
{
private:
    bool m_computerInPlay = false;
    bool m_foundWinner = false;
    bool m_gameOver = false;

    void restartGame(Board& board, Turn& turn);

public:
    static const int WINNING_ROW = 4;

    void game(GameLogic& gameLogic, Player& player1, Player& player2, Board& board, Turn& turn);
    bool isComputerInplay() { return m_computerInPlay; }
    bool isWinnerFound() { return m_foundWinner; }
    void setComputerToPlay(bool inPlay);

    bool isGameOver() { return m_gameOver; }
    bool isRoundOver() { return m_foundWinner; }
    void promptRestart(Board& board, Turn& turn);
};
