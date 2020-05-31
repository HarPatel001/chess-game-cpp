#include "player.h"

typedef std::vector<Piece*> Pieces;
Player::Player(Pieces pieces, std::string color)
{
    for(auto* piece : pieces)
    {
        if ((piece->getImageName().find(color)) != -1)
        {
            m_pieces.push_back(piece);
        }
    }

    bool turn = false;
}

Player::~Player() {}

bool Player::getTurn()
{
    return turn;
}

void Player::setTurn(bool isTurn) 
{
    turn = isTurn;
}

Pieces Player::getPieces()
{
    return m_pieces;
}

void Player::setPieces(Pieces pieces, std::string color)
{
    m_pieces.clear();
    for(auto* piece : pieces)
    {
        if ((piece->getImageName().find(color)) != -1)
        {
            m_pieces.push_back(piece);
        }
    }
}