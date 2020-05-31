#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece
{
public:
    Rook(int x, int y, std::string iname);
    ~Rook();
    void move(int x, int y) override;;
    bool validateMove(int x, int y) override;
private:
    bool moved;
};

#endif