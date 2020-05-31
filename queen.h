#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
public:
    Queen(int x, int y, std::string iname);
    ~Queen();
    void move(int x, int y) override;;
    bool validateMove(int x, int y) override;
};

#endif