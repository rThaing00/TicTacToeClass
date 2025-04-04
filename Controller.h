//
// Created by Raymond Thaing on 3/17/25.
//

#ifndef TICTACTOECLASS_CONTROLLER_H
#define TICTACTOECLASS_CONTROLLER_H

#include "Player.h"
#include "Board.h"
#include <iostream>

class Controller
{
private:
    static Pair convertToCoord(int number, const Board & board);
    bool player1sTurn = true;
    bool tieGame(const Board & board) const;
    bool isWinner(const Board & board) const;
    bool isWinner(const Board & board, char mark) const;


public:
    Controller();
    void getPlayerInput(Player & player,const Board & board);
    void updateBoard(const Player & player, Board & board);
    const Player & choosePlayer(Player & player1,Player & player2);
    const Player & switchPlayer(const Player & player1, const Player & player2);
    bool gameOver(const Board & board);
    std::string winner(const Player & player1, const Player & player2,
            const Board & board);
};


#endif //TICTACTOECLASS_CONTROLLER_H
