#include "piece.h"
#include <iostream>

Piece::Piece(int x, int y) : _x{x}, _y{y} {}

Piece::Piece(int x, int y, std::string iname) : Piece(x, y) 
{
    imageName = iname;
}


int Piece::getx()
{
    return Piece::_x;
}

int Piece::gety()
{
    return Piece::_y;
}

bool Piece::isLocated(int x, int y)
{
    if ((Piece::_x == x) && (Piece::_y == y))
    {
        return true;
    }
    return false;
    
}

std::string Piece::getImageName()
{
    return Piece::imageName;
}