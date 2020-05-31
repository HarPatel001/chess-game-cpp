#include "board.h"
#include <iostream>

Board::Board() : first_click{true} //declares click will be first click
{
    
    Board::pieces.clear();
    grid = Gtk::manage(new Gtk::Grid);
    grid->set_hexpand(true);
    grid->set_vexpand(true);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
          
            if (j == 1)
            {
                pieces.push_back(new Pawn(i, j, "images/pawn_w.png"));
            }
            else if (j == 6)
            {
                pieces.push_back(new Pawn(i, j, "images/pawn_b.png"));
            }

            if (j == 0) 
            {
                if (i == 0 || i == 7) 
                {
                    pieces.push_back(new Rook(i, j, "images/rook_w.png"));
                }
                else if (i == 1 || i == 6)
                {
                    pieces.push_back(new Knight(i, j, "images/knight_w.png"));
                }
                else if (i == 2 || i == 5)
                {
                    pieces.push_back(new Bishop(i, j, "images/bishop_w.png"));
                }
                else if (i == 3)
                {
                    pieces.push_back(new Queen(i, j, "images/queen_w.png"));
                }
                else 
                {
                    pieces.push_back(new King(i, j, "images/king_w.png"));
                }
            }
            else if (j == 7)
            {
                if (i == 0 || i == 7) 
                {
                    pieces.push_back(new Rook(i, j, "images/rook_b.png"));
                }
                else if (i == 1 || i == 6)
                {
                    pieces.push_back(new Knight(i, j, "images/knight_b.png"));
                }
                else if (i == 2 || i == 5)
                {
                    pieces.push_back(new Bishop(i, j, "images/bishop_b.png"));
                }
                else if (i == 4)
                {
                    pieces.push_back(new Queen(i, j, "images/queen_b.png"));
                }
                else 
                {
                    pieces.push_back(new King(i, j, "images/king_b.png"));
                }
            }
        }
    }

}

Board::~Board()
{
    //need a deconstructor that deletes heap memory of pieces and board
}

std::vector<Piece*>::iterator Board::begin() {return pieces.begin();}

std::vector<Piece*>::iterator Board::end() {return pieces.end();}

Gtk::Grid* Board::getGrid() {return Board::grid;}

std::vector<Piece*>& Board::getPieces()
{
    return pieces;
}

void Board::clicked() 
{
    first_click = !first_click;
    
}

bool Board::is_first_click() 
{
    return this->first_click;
}

int Board::getPosition(int i, int j, std::vector<Piece*> m_pieces)
{
    int count = 0;
    for(auto piece: m_pieces)
    {
        if (piece->isLocated(i, j))
        {
            return count;
        }
        ++count;
    }
    return -1;
}


void Board::setIsFirstClick(bool click)
{
    first_click = click;
}
 
bool Board::isPathClear(int a, int b, Piece* piece, std::vector<Piece*> m_pieces)
{
    int x = piece->getx();
    int y = piece->gety();
    std::cout << "H" << piece->getx() << a << std::endl;

    for(auto* mpiece : m_pieces)
    {
        if (mpiece->isLocated(a, b))
        {
            return false;
        }
    }


    if (piece->getImageName().find("pawn") != -1) //check if some piece is in front of pawn
    {
	// check if moving diagonally only if opponent piece is there to be captured
	if (abs(piece->getx() - a) == 1)
	{
	    
	    for(auto* mpiece : pieces)
            {
                if (mpiece->isLocated(a, b))
                {
                    return true;
                }
            }
	    return false;
	}
	// if moving vertically, check if there is a piece that blocks pawn
	if (abs(piece->getx() - a) == 0)
	{
	    for(auto* mpiece : pieces)
            {
                if (mpiece->isLocated(a, b))
                {
                    return false;
                }
            }
	}
    }

    
    if (piece->getImageName().find("knight") != -1) //check if piece is knight, no pieces in path matter
    {
        return true;
    }


    while (true)
    {
        if (a != x) 
        {
            if (a < x) 
            {
                a++;
            }
            else
            {
                a--;
            }
            
            
        }
        if (b != y) 
        {
            if (b < y) 
            {
                b++;
            }
            else
            {
                b--;
            }
        }

        if((a == x) && (b == y))
        {
            return true;
        }
        
        else
        {
            for(auto* mpiece: pieces)
            {
                if (mpiece->isLocated(a, b))
                {
                    return false;
                }
                
            }
        }
    }
    return true;

}
