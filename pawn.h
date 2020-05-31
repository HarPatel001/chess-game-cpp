#include "piece.h"
#ifndef PAWN_H
#define PAWN_H

class Pawn : virtual public Piece
{
public:
    Pawn(int x, int y, std::string iname);
    void move(int x, int y) override;
    bool validateMove(int x, int y) override;

private:
    bool moved;
};

#endif