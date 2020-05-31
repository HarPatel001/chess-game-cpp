#include "bishop.h"

Bishop::Bishop(int x, int y, std::string iname): Piece(x, y, iname) {}

Bishop::~Bishop() {}

void Bishop::move(int x, int y)
{
    
    Bishop::_x = x;
    Bishop::_y = y;
} 
    
bool Bishop::validateMove(int x, int y)
{
    if ( ((_x - x) == (_y - y)) || ((_x -x) == (y - _y)) )
    {
        return true;
    }
    return false;
}