#include <string.h>
#include <gtkmm.h>
#ifndef PIECE_H
#define PIECE_H

class Piece
{
    public:
    Piece(int x, int y);
    Piece(int x, int y, std::string iname);
    virtual void move(int x, int y) = 0;
    virtual bool validateMove(int x, int y) = 0;
    int getx();
    int gety();
    bool isLocated(int x, int y);
    std::string getImageName();

    protected:
    bool clicked = false;
    int _x;
    int _y;
    std::string imageName;
};


#endif