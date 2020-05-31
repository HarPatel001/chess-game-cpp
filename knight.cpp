#include "knight.h"

Knight::Knight(int x, int y, std::string iname): Piece(x, y, iname) {}

Knight::~Knight() {}

void Knight::move(int x, int y)
{
    Knight::_x = x;
    Knight::_y = y;
} 

bool Knight::validateMove(int x, int y)
{
    if ( ( (abs(_x - x) == 1) && (abs(_y - y) == 2) ) || ( (abs(_x - x) == 2) && (abs(_y - y) == 1) ) )
    {
        return true;
    }
    return false;
}