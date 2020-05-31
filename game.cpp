#include "game.h"
#include <iostream>

Game::Game() : player1(board.getPieces(), "_w"), player2(board.getPieces(), "_b"), _moves{0}
{
    player1.setTurn(true);
    player2.setTurn(false);
}

Game::~Game() {}

Board Game::getBoard()
{
    return board;
}

Player& Game::getPlayer(int n)
{
    if (n == 1)
    {
        return player1;
    }
    else if (n == 2)
    {
        return player2;
    }
}

void Game::onButtonClicked(int i, int j, Gtk::Button* button)
{
    
    if (board.is_first_click())
    {
        //pass in only the vector of active player's pieces
        if(board.getPosition(i, j, getActivePlayer().getPieces()) != -1)
        {
            _first_piece = board.getPosition(i, j, board.getPieces()); //piece index in full vector
            _first_button = button;
            _button_x = i;
            _button_y = j;
            board.clicked();
            Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
            css_provider->load_from_data("button {background-image: image(#30b5ec);}");
            button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
        }

    }
    else
    {
        if (_first_piece == board.getPosition(i, j, getActivePlayer().getPieces()))
        {
            board.setIsFirstClick(true);
        }
        else if (!(board.getPieces().at(_first_piece)->validateMove(i, j))) //if invalid move
        {
            // Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
            // css_provider->load_from_data("body {background-image: image(#ff0000);}");
            // label->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
            std::string msg = "Illegal Move " + getMessage();
            // label->set_text(msg);
            // Gtk::MessageDialog* dialog = Gtk::manage(new Gtk::MessageDialog(*this, "", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true));
            // dialog->set_message(msg, false);
            // dialog->run();
            board.setIsFirstClick(true);
        }
        else if (board.getPieces().at(_first_piece)->validateMove(i, j)) //if valid move
        {
            //pass in i, j, player's pieces
	  if (board.isPathClear(i, j, board.getPieces().at(_first_piece), getActivePlayer().getPieces())) 
            {
                std::string tile_image = board.getPieces().at(_first_piece)->getImageName();
                board.getPieces().at(_first_piece)->move(i, j);
                capture(i, j);
                Gtk::Image* image = Gtk::manage(new Gtk::Image{tile_image});
                button->set_image(*image);
                remove_image();
                board.clicked();
                endMove();
            }
            else
            {
                board.setIsFirstClick(true);
            }
            
        }
        removeBackground(_first_button, _button_x, _button_y);
    }
}

void Game::remove_image()
{
    std::string tile_image = "images/black_square.png";
    //if i and j are not both even or both odd
    if ((_button_x + _button_y) % 2 != 0)
    {
        tile_image = "images/white_square.png";   
    }
    Gtk::Image *image = Gtk::manage(new Gtk::Image{tile_image});
    _first_button->set_image(*image);
    return;
}

void Game::removeBackground(Gtk::Button* button, int i, int j)
{
    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
    css_provider->load_from_data("button {background-image: image(#4cc875);}");
    button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    //if i and j are not both even or both odd
    if ((i + j) % 2 != 0)
    {
        css_provider->load_from_data("button {background-image: image(#f3f48c);}");
        button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    }
}

void Game::setButtons(std::vector<Gtk::Button*>& buttons)
{
    buttons = buttons;
}

Player Game::getActivePlayer()
{
    if (player1.getTurn()) {return player1;}
    else if (player2.getTurn()) {return player2;}
}

Player Game::getNonActivePlayer()
{
    if (!player1.getTurn()) {return player1;}
    else if (!player2.getTurn()) {return player2;}
}

void Game::endMove()
{
    _moves++;
    if ( (_moves % 2) == 0 )
    {
        player1.setTurn(true);
        player2.setTurn(false);
    }
    else
    {
        player1.setTurn(false);
        player2.setTurn(true);
    }
    
}

std::string Game::getMessage()
{
    if ((_moves % 2) == 0)
    {
        return "Player 1's turn";
    }
    else
    {
        return "Player 2's turn";
    }
    
}

void Game::capture(int a, int b)
{
    int count = 0;
    for(auto* mpiece : getNonActivePlayer().getPieces())
    {
        count = 0;
        if (mpiece->isLocated(a, b))
        {
            for (auto* p_piece : board.getPieces())
            {
                if (p_piece->isLocated(a, b))
                {
                    if ( (p_piece->getImageName().find(mpiece->getImageName())) != -1) 
                    {
                        board.getPieces().erase(board.getPieces().begin() + count);
                        if (!player1.getTurn()) 
                        {
                            player1.setPieces(board.getPieces(), "_w");
                        }
                        else
                        {
                            player2.setPieces(board.getPieces(), "_b");
                        }
                        
                        return;
                    }
                    
                }
                count++;
            }
            
        }
    }
}

int Game::checkStatus()
{
    int count_b = 0, count_w = 0;
    for(auto* piece : board.getPieces())
    {
        if ((piece->getImageName().find("king_w")) != -1)
        {
            count_w++;
        }
        else if ((piece->getImageName().find("king_b")) != -1)
        {
            count_b++;
        }
    }
    if (count_w == 0)
    {
        return 2; //player 2 won
    }
    else if (count_b == 0)
    {
        return 1; //player 1 won
    }
    
    return 0;
}

void Game::setLabel(Gtk::Label* label)
{
    label = label;
}
