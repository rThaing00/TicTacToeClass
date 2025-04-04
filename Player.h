//
// Created by Raymond Thaing on 3/17/25.
//

#ifndef TICTACTOECLASS_PLAYER_H
#define TICTACTOECLASS_PLAYER_H

struct Pair
{
    int row,col;
};

class Player
{
private:
    int _row, _col;
    char _mark;
public:
    Player();
    Player(char mark);
    Player(Pair pair, char mark);

    char getMark() const;
    void setMark(char mark);

    int getRow() const;
    void setRow(int _row);

    int getCol() const;
    void setCol(int _col);

    void setRow_and_Col(Pair pair);
    Pair getRow_and_Col() const;



};


#endif //TICTACTOECLASS_PLAYER_H
