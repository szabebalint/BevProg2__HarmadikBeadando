#include "application.hpp"
#include "widgets.hpp"

using namespace genv;

Application::Application(int width, int height)
{
    gout.open(width, height);
    gout.load_font("LiberationSans-Regular.ttf", 50);
    //gout.load_font("LiberationSans-Regular.ttf", 15);
}

void Application::screen_clear()
{
    gout << move_to(0,0) << color(0,0,0) << box(800,600);
}

Turn Application::turn()
{
    return _turn;
}

void Application::set_turn(Turn t)
{
    _turn = t;
}

Phase Application::phase()
{
    return _phase;
}
void Application::set_phase(Phase p)
{
    _phase = p;
}

void Application::add_widget(Widget* w)
{
    switch (w->phase())
    {
    case MAIN_MENU:
        main_menu.push_back(w);
        break;
    case GAME:
        game.push_back(w);
        break;
    case GAME_OVER:
        gameover_screen.push_back(w);
        break;
    }
}


//void Application::event_loop()




