#include "queen.h"

Queen::Queen(int x, int y, std::string iname): Piece(x, y, iname) {}

Queen::~Queen() {}

void Queen::move(int x, int y)
{
    Queen::_x = x;
    Queen::_y = y;
} 

bool Queen::validateMove(int x, int y)
{
    if ( (abs(_x - x) == 0) && (abs(_y - y) != 0) )
    {
        return true;
    }
    if ( (abs(_y - y) == 0) && (abs(_x - x) != 0) )
    {
        return true;
    }
    if ( ((_x - x) == (_y - y)) || ((_x -x) == (y - _y)) )
    {
        return true;
    }
    return false;
}