#include "pawn.h"

Pawn::Pawn(int x, int y, std::string iname) : Piece(x, y, iname), moved{false} {}

void Pawn::move(int x, int y) 
{
    Pawn::_x = x; 
    Pawn::_y = y;
    moved = true;
};

bool Pawn::validateMove(int x, int y)
{
    if (imageName.find("_w") != -1) 
    {
        if ((_y - y) > 0) //if moving backwards
        {
            return false;
        }
    }
    else
    {
        if ((y - _y) > 0) //if moving backwards
        {
            return false;
        }
    }
    
    
    if (!moved)
    {
        if ( abs (_y - y) > 2  ) 
        {
            return false;
        }
    }
    if (moved) 
    {
        if ( abs (_y - y) > 1  ) 
        {
            return false;
        }
    }
    
    if ( ( abs(_x - x) == 1) && (abs(_y - y) > 0) ) 
    {
        return true;
    }
    

    if((_x - x) != 0)
    {
        return false;
    }
    
    return true;
}


