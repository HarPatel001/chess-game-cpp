#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece
{
public:
    King(int x, int y, std::string iname);
    ~King();
    void move(int x, int y) override;;
    bool validateMove(int x, int y) override;
private:
    bool moved;
};

#endif