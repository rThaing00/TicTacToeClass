//
// Created by Raymond Thaing on 3/17/25.
//

#include "Controller.h"


Controller::Controller()
{

}

void Controller::getPlayerInput(Player & player,const Board & board)
{
    int number;
    std::cin >> number;
    Pair p = convertToCoord(number,board);
    player.setRow_and_Col(p);

}
void Controller::updateBoard(const Player & player, Board & board)
{
    Pair p = player.getRow_and_Col();
    board.setBoard(p.row,p.col,player.getMark());
}
Pair Controller::convertToCoord(int number, const Board & board)
{
//     / divide for row
//      % mod for col
return {(number - 1) / board.getRowSize(),(number - 1) % board.getColSize()};
}
///ask who wants to go first return the correct player
///ask to choose a mark(other player would then get other mark
const Player & Controller::choosePlayer( Player & player1, Player & player2)
{
    int choice;
    char mark, otherMark;
    do
    {
        std::cout << "Who is going first? 1 or 2 ";
        std::cin >> choice;
    }
    while(choice != 1 && choice != 2);
    do
    {
        std::string player = "Player" + std::to_string(choice);
        std::cout << player << " choose a mark(X or O): ";
        std::cin >> mark;
        mark = std::toupper(mark);
    }
    while(mark != 'X'&& mark != 'O');
    do
    {
        otherMark = mark == 'X' ? 'O' : 'X';
        //// variable  = mark statement ? if bool statment true /// if bool stoi(board.getMark(0,2))statement false
        if(choice == 1)
        {
            player1.setMark(mark);
            player2.setMark(otherMark);
            player1sTurn =  true;
        }
        else
        {
            player2.setMark(mark);
            player1.setMark(otherMark);
            player1sTurn = false;
        }

    }
    while(choice!= 1 && choice != 2);

    return choice == 1 ? player1 : player2;
}
///if the last player was player 1 then reutnr player2 other wise reutnr player1
const Player & Controller::switchPlayer(const Player & player1, const Player & player2)
{
    player1sTurn = !player1sTurn;
    return player1sTurn ? player1 : player2;
}
/// if there is a winner or if all spaces in the board has been marked return true
///otherwise return false
bool Controller::gameOver(const Board & board)
{
    return tieGame(board) || isWinner(board);
}
///return a string containing X Wins , 0 Wins, or it is a tie!
std::string Controller::winner(const Player & player1, const Player & player2,
                   const Board & board)
{
    std::string s;
    if(isWinner(board,player1.getMark()))
    {
        s+= "\n";
        s += player1.getMark();
        s += " wins!!";
    }
    else if (isWinner(board,player2.getMark()))
    {
        s+= "\n";
        s += player2.getMark();
        s += " wins!!";
    }
    if(tieGame(board))
    {
        s+= "\n Game ends in a tie. ";
    }
    return s;
}

bool Controller::tieGame(const Board & board) const
{
    for (int i = 0; i < board.getRowSize();i ++)
    {
        for(int j= 0; j < board.getColSize();j++)
        {
            if (isdigit(board.getMark(i,j).at(0)))
            /// checks to see if there is a number in the board
            {
                return false;
                ///returns false if the board is not filled up yet
                /// or not tie yet
            }
        }
    }
    return true;
}
bool Controller::isWinner(const Board & board) const
{
    return isWinner(board,'X') || isWinner(board,'O');
}

bool Controller::isWinner(const Board & board, char mark) const
{
    ///check rows
    ///check cols
    ///check diagonals

    int markingRow;
    int markingColumn;
    /// for col and row
    for (int i = 0; i < board.getRowSize(); ++i)
    {
        markingRow = 0;
        markingColumn = 0;
        for (int j = 0; j < board.getColSize(); ++j)
        {
            if(board.getMark(i,j).at(0) == mark)
            {
                markingRow++;
            }

            if(board.getMark(j,i).at(0) == mark)
            {
                markingColumn++;
            }
            if(markingRow == board.getColSize() || markingColumn == board.getColSize())
            {
                return true;
            }
        }
    }
    ///the diagonals
    if( board.getMark(0,2).at(0) == mark && board.getMark(1,1).at(0) == mark && board.getMark(2,0).at(0)== mark)///checks first diagonal
    {
        return true;
    }
    if(board.getMark(0,0).at(0) == mark &&  board.getMark(1,1).at(0)== mark && board.getMark(2,2).at(0) == mark)///checks second diagonal
    {
        return true;
    }
    return false;
}