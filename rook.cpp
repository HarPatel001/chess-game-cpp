#include "rook.h"

Rook::Rook(int x, int y, std::string iname): Piece(x, y, iname), moved{false} {}

Rook::~Rook() {}

void Rook::move(int x, int y)
{
    Rook::_x = x;
    Rook::_y = y;
    moved = true;
} 

bool Rook::validateMove(int x, int y)
{
    if ( (abs(_x - x) == 0) && (abs(_y - y) != 0) )
    {
        return true;
    }
    if ( (abs(_y - y) == 0) && (abs(_x - x) != 0) )
    {
        return true;
    }
    return false;
}