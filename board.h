#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
#include <vector>

class Board
{
private:
    typedef std::vector<Piece*> Pieces;
    Pieces pieces; 
    Gtk::Grid* grid;
    bool first_click;
public:
    Board();
    // Board(const Board&) // need copy const, copy asssign and destructor...then change in mainwindow.cpp board to * ->  
    ~Board();
    typedef Pieces::iterator iterator;
    typedef Pieces::const_iterator const_iterator;
    iterator begin();
    iterator end();
    Gtk::Grid* getGrid();
    Pieces& getPieces();
    bool is_first_click();
    void clicked();
    void setIsFirstClick(bool click);
    int getPosition(int i, int j, Pieces m_pieces);
    bool isPathClear(int a, int b, Piece* piece, Pieces m_pieces);
};


#endif
