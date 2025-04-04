//
// Created by Raymond Thaing on 3/20/25.
//

#include "TicTacToe.h"



void TicTacToe::run()
{

    char goAgain;
    do
    {
        _board.reset();
        gameLogic();
        std::cout << "Do you want to go again?";
        std::cin >> goAgain;
    }
    while(std::tolower(goAgain) == 'y');


}

void TicTacToe::gameLogic()
{
    int boardSize;
    _currentPlayer = _controller.choosePlayer(_player1,_player2);
    do
    {
        /// for me ask for the size of the board


        ///draw the board
        std::cout << _board.to_String();
        ///tell the current player to choose a spot
        std::cout <<"\n"<<_currentPlayer.getMark() << " choose a spot: ";
        _controller.getPlayerInput(_currentPlayer,_board);
        ///update board with player data
        _controller.updateBoard(_currentPlayer,_board);
        ///switch players
        _currentPlayer = _controller.switchPlayer(_player1,_player2);
    }
        ///check to see if the game is over
    while(!_controller.gameOver(_board));

    ///loop ends
    std::cout << _board.to_String();
    ///check who won or if tie
    std::cout << _controller.winner(_player1,_player2,_board);
    ///print result
    ///ask if you want to player again
}