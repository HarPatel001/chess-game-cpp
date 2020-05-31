#include "piece.h"
#include "board.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef std::vector<Piece*> Pieces;
class Player
{
private:
    Pieces m_pieces;
    bool turn;
public:
    Player(Pieces pieces, std::string color);
    ~Player();
    bool getTurn();
    void setTurn(bool isTurn);
    Pieces getPieces();
    void setPieces(Pieces pieces, std::string color);
};


#endif