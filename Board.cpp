//
// Created by Raymond Thaing on 3/17/25.
//

#include "Board.h"



Board::Board()
:Board(3,3)
{

}
Board::Board(int row, int col)
: _board(row,std::vector<std::string> (col, ""))
// 2d vector is a vector of vectors
// _board(# of rows, #of col(another vector))
{

}


//setter
void Board::setBoard(int row, int col, char mark)
{
    _board.at(row).at(col).at(0) = mark;
    //line above checks for errors;
    //checks to see if there is enough memory?
//     _board[row][col] = mark;
}

std::string Board::getMark(int row, int col) const
{
    return _board.at(row).at(col);
}

std::string Board::to_String() const
{
//    " 1 | 2 | 3 |"
//    "---+---+----"
//    " 4 | 5 | 6 |"
//    "---+---+----"
//    " 7 | 8 | 9 |"
    std::string result;
    int row = 0;
    int maxNumber = getMaxNumber();
    int bufferNumber = 3;
    bool bigNumber;

    if(maxNumber > 99)
    {
        bufferNumber = 2;
        bigNumber = true;
    }

    int dashNumber = getNumberOfDigits(maxNumber) + bufferNumber;
    for (const std::vector<std::string> & v : _board)
    {
        std::string dashes;
        int col = 0;
        for (const std::string & s : v)
        {
            result.push_back(' ');

            if(_board.at(row).at(col).length() < 2)
            {
                result.push_back(' ');
            }
            else if(_board.at(row).at(col).length() < 3 && bigNumber){
                result.push_back(' ');
            }

            result += s;

            if(_board.at(row).at(col).length() < 2 && bigNumber)
            {
                result.push_back(' ');
            }

            result.push_back(' ');
            if(col< v.size() - 1 )
                result.push_back('|');
            dashes += std::string (dashNumber - 1, '-') + "+";
            col++;
        }
        dashes.pop_back();
        if(row < _board.size() - 1)
        {
            result += "\n" + dashes + "\n";
        }
        row++;

    }
    return result;
}

int Board::getMaxNumber() const
{
    return _board.size() * _board.at(0).size() + 1;
}
int Board::getNumberOfDigits(int number)
{
    int count = 0;
    while(number > 0)
    {
        number /= 10;
        count ++;
    }
    return count;
}
int Board::getRowSize() const
{
    return _board.at(0).size();
}
int Board::getColSize() const
{
    return _board.size();
}

void Board::reset()
{
    int count = 1;
    for(int i = 0; i < _board.size() ;++i)
    {
        for( int j = 0; j< _board.at(i).size() ;++j)
        {
            _board.at(i).at(j) = std::to_string(count++);
        }
    }
}