//
// Created by Raymond Thaing on 3/20/25.
//

#ifndef TICTACTOECLASS_TICTACTOE_H
#define TICTACTOECLASS_TICTACTOE_H


#include "Board.h"
#include "Player.h"
#include "Controller.h"

class TicTacToe
{
    Board _board;
    Player _player1, _player2, _currentPlayer;
    Controller _controller;
    void gameLogic();
public:
    void run();

};


#endif //TICTACTOECLASS_TICTACTOE_H
