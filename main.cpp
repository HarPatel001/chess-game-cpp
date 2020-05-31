#include "main_window.h"
#include <gtkmm.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "Chess Game");

    Main_window win;

    return app->run(win);

}