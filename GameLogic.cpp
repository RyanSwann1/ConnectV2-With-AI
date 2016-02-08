#include "stdafx.h"
#include "GameLogic.h"
#include "Board.h"
#include "Player.h"
#include "computerPlayer.h"
#include "Turn.h"


void GameLogic::game(GameLogic& gameLogic, Player & player1, Player & player2, Board & board, Turn& turn)
{
    while (!isGameOver())
    {
        turn.decideFirstTurn(player1, player2);
        board.display();

        while (!isRoundOver())
        {
            if (turn.getTurn() == player1.getGamePiece())
            {
                turn.announceTurn("Player 1");
                player1.takeTurn(board);
                board.display();
                m_foundWinner = board.findWinner(gameLogic, board, player1.getGamePiece());
                turn.changeTurn(turn.getTurn());
            }

            if (!m_foundWinner)
            {
                turn.announceTurn("Player 2");
                player2.takeTurn(board);
                board.display();
                m_foundWinner = board.findWinner(gameLogic, board, player2.getGamePiece());
                turn.changeTurn(turn.getTurn());
            }
        }
        promptRestart(board, turn);
    }

}


void GameLogic::setComputerToPlay(bool inPlay)
{
    if (inPlay) {
        m_computerInPlay = true;
    }
    else {
        m_computerInPlay = false;
    }
}

void GameLogic::promptRestart(Board& board, Turn& turn)
{
    bool decided = false;
    char responce = ' ';
    while (!decided)
    {
        std::cout << "\nWould you like to play again? 'y' - Yes. 'n' - No.";
        std::cin >> responce;

        if (responce == 'y' || responce == 'n') {
            decided = true;
        }
    }

    if (responce == 'n') {
        m_gameOver = true;
    }
    else {
        restartGame(board, turn);
    }
}

void GameLogic::restartGame(Board& board, Turn& turn)
{
    m_foundWinner = false;
    m_gameOver = false;
    turn.setFirstTurn();

    board.clear();
}
