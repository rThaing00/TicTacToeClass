//
// Created by Raymond Thaing on 3/17/25.
//

#ifndef TICTACTOECLASS_BOARD_H
#define TICTACTOECLASS_BOARD_H

#include <vector>
#include <string>

class Board
{
private:
    std::vector<std::vector<std::string>> _board;
    int getMaxNumber() const;
    static int getNumberOfDigits(int number);

public:
    Board();
    Board(int row, int col);

    void setBoard(int row, int col, char mark);
    std::string getMark(int row, int col) const;
    std::string to_String() const;
    int getRowSize() const;
    int getColSize() const;
    void reset();




};

#endif //TICTACTOECLASS_BOARD_H
