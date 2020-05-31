#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{

private:
    Board board;
    Player player1;
    Player player2;
    int _moves;
    int _first_piece;
    int _next;
    Gtk::Button* _first_button;
    int _button_x;
    int _button_y;
    std::vector<Gtk::Button*> buttons;
    Gtk::Label* label;
public:
    Game();
    ~Game();
    Board getBoard();
    Player& getPlayer(int n);
    void setButtons(std::vector<Gtk::Button*>& buttons);
    void onButtonClicked(int i, int j, Gtk::Button* button);
    void remove_image();
    void removeBackground(Gtk::Button* button, int i, int j);
    Player getActivePlayer();
    Player getNonActivePlayer();
    void endMove();
    std::string getMessage();
    void capture(int a, int b);
    int checkStatus();
    void setLabel(Gtk::Label* label);
};


#endif