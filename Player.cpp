//
// Created by Raymond Thaing on 3/17/25.
//

#include "Player.h"


Player::Player()
:Player({0,0},'X')
// could also do :Player(Pair{0,0}, 'X')
{

}
Player::Player(Pair pair, char mark)
:_row(pair.row),_col(pair.col), _mark(mark)
{

}
Player::Player(char mark)
:Player({0,0}, mark)
{

}
char Player::getMark() const
{
    return _mark;
}
void Player::setMark(char mark)
{
    _mark = mark;
}

int Player::getRow() const
{
    return _row;
}
void Player::setRow(int row)
{
    // no ambeguiity?(idk how to spell it)
    // don't need Player::_row = row;
    // different name so, you can just use the bottom
    _row = row;
}

int Player::getCol() const
{
    return _col;
}
void Player::setCol(int col)
{
    _col = col;
}

void Player::setRow_and_Col(Pair pair)
{
    ///when we want to access something public
    ///use the dot operator

    _row = pair.row;
    _col = pair.col;
}
Pair Player::getRow_and_Col() const
{
    return {_row,_col};
}