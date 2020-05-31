#include "main_window.h"
#include <gtkmm.h>

Main_window::Main_window()
{
    set_default_size(500, 500);
    set_title("Chess Game");

    vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PackOptions::PACK_SHRINK, 0); //pack_shrink packs it shrinked, 0 for padding

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);

    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Game", true));
    menuitem_new->signal_activate().connect([this] { this->on_new_clicked(); });
    filemenu->append(*menuitem_new);

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    Gtk::ToolButton *new_game_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_game_button->set_tooltip_markup("Create a new name, discarding any in progress");
    new_game_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_clicked));
    toolbar->append(*new_game_button);


    board = game.getBoard();

    grid = Gtk::manage(board.getGrid());
    grid->set_hexpand(true);
    grid->set_vexpand(true); 

    // reverse for j because grid is added top down

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Gtk::Button *button = Gtk::manage(new Gtk::Button());
            std::string tile_image = "images/black_square.png";
            Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
            css_provider->load_from_data("button {background-image: image(#4cc875);}\
                                            button:active {background-image: image(#30b5ec)}");
            button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
            //if i and j are not both even or both odd
            if ((i + j) % 2 != 0)
            {
                css_provider->load_from_data("button {background-image: image(#f3f48c);}");
                button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
                tile_image = "images/white_square.png";   
            }

            for (auto piece: board.getPieces())
            {
                if(piece->isLocated(i, j))
                {
                    tile_image = piece->getImageName();
                }
            }
            Gtk::Image *image = Gtk::manage(new Gtk::Image{tile_image});

            button->set_image(*image);
            button->signal_clicked().connect([this, i, j, button] { this->on_button_clicked(i, j, button); });
            grid->attach(*button, i, 7-j, 1, 1);
            buttons.push_back(button);
        }
    }
    vbox->add(*grid);

    statusbar = Gtk::manage(new Gtk::Statusbar);
    label = Gtk::manage(new Gtk::Label());
    game.setLabel(label);
    label->set_label(game.getMessage());
    statusbar->set_center_widget(*label);
    vbox->add(*statusbar);
    vbox->show_all();
    game.setButtons(buttons);

}

Main_window::~Main_window() {}

void Main_window::on_button_clicked(int i, int j, Gtk::Button* button)
{
    game.onButtonClicked(i, j, button);
    label->set_label(game.getMessage());
    int w = game.checkStatus();
    if( w == 1)
    {
	//cannot add Gtk::manage since there is no parent controller for a gtk window so dialog will never go away(delete) even after clicking button OK
        Gtk::MessageDialog* dialog = new Gtk::MessageDialog(*this, "Winner", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
        dialog->set_secondary_text("PLAYER 1 WON", false);
        dialog->run();
	delete dialog;
        // label->set_label("PLAYER 1 WON");
    }
    if( w == 2)
    {
        Gtk::MessageDialog* dialog = new Gtk::MessageDialog(*this, "Winner", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
        dialog->set_secondary_text("PLAYER 2 WON", false);
        dialog->run();
	delete dialog;
        // label->set_label("PLAYER 2 WON");
    }
    // rotateBoard();
}

void Main_window::on_new_clicked()
{
    game = *(new Game());
    board = game.getBoard();
    vbox->remove(*grid);
    vbox->remove(*statusbar);
    grid = board.getGrid();
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Gtk::Button *button = Gtk::manage(new Gtk::Button());
            std::string tile_image = "images/black_square.png";
            Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
            css_provider->load_from_data("button {background-image: image(#4cc875);}\
                                            button:active {background-image: image(#30b5ec)}");
            button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
            //if i and j are not both even or both odd
            if ((i + j) % 2 != 0)
            {
                css_provider->load_from_data("button {background-image: image(#f3f48c);}");
                button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
                tile_image = "images/white_square.png";   
            }

            for (auto piece: board.getPieces())
            {
                if(piece->isLocated(i, j))
                {
                    tile_image = piece->getImageName();
                }
            }
            Gtk::Image *image = Gtk::manage(new Gtk::Image{tile_image});

            button->set_image(*image);
            button->signal_clicked().connect([this, i, j, button] { this->on_button_clicked(i, j, button); });
            grid->attach(*button, i, 7-j, 1, 1);
            buttons.push_back(button);
        }
    }
    vbox->add(*grid);
    label->set_label(game.getMessage());
    vbox->add(*statusbar);
    vbox->show_all();
}

// void Main_window::rotateBoard()
// {
//     vbox->remove(*grid);
//     vbox->remove(*statusbar);
//     grid = Gtk::manage(new Gtk::Grid());
//     for(int i = 0; i < 8; i++)
//     {
//         for(int j = 0; j < 8; j++)
//         {
//             Gtk::Button *button = Gtk::manage(new Gtk::Button());
//             std::string tile_image = "images/black_square.png";
//             Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
//             css_provider->load_from_data("button {background-image: image(#4cc875);}\
//                                             button:active {background-image: image(#30b5ec)}");
//             button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
//             //if i and j are not both even or both odd
//             if ((i + j) % 2 != 0)
//             {
//                 css_provider->load_from_data("button {background-image: image(#f3f48c);}");
//                 button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
//                 tile_image = "images/white_square.png";   
//             }

//             for (auto piece: board.getPieces())
//             {
//                 if(piece->isLocated(i, j))
//                 {
//                     tile_image = piece->getImageName();
//                 }
//             }
//             Gtk::Image *image = Gtk::manage(new Gtk::Image{tile_image});

//             button->set_image(*image);
//             button->signal_clicked().connect([this, i, j, button] { this->on_button_clicked(i, j, button); });
//             grid->attach(*button, 7- i, j, 1, 1);
//             buttons.push_back(button);
//         }
//     }
//     vbox->add(*grid);
//     label->set_label(game.getMessage());
//     vbox->add(*statusbar);
//     vbox->show_all();
// }  Not so sure about this approach, too much switching grids,, prolly have two grids, show diff each time

// void Main_window::onLoadClicked()
// {
//     try() //
// }
