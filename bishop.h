#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(int x, int y, std::string iname);
    ~Bishop();
    void move(int x, int y) override;
    bool validateMove(int x, int y) override;
};

#endif