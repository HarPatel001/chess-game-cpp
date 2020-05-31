#include "king.h"

King::King(int x, int y, std::string iname): Piece(x, y, iname), moved{false} {}

King::~King() {}

void King::move(int x, int y)
{
    King::_x = x;
    King::_y = y;
    moved == true;
} 

bool King::validateMove(int x, int y)
{
    int xd = _x - x;
    int yd = _y - y;
    if ( (xd > 1) || (xd < -1) || (yd > 1) || (yd < -1) )
    {
        return false;
    }
    return true;
}