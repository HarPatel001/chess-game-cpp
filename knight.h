#ifndef KNIGHT_H
#define KINGHT_H
#include "piece.h"

class Knight : public Piece
{
public:
    Knight(int x, int y, std::string iname);
    ~Knight();
    void move(int x, int y) override;;
    bool validateMove(int x, int y) override;
};

#endif