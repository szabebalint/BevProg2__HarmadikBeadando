#include "application.hpp"
#include "widgets.hpp"

using namespace genv;

Application::Application(int width, int height)
{
    gout.open(width, height);
    gout.load_font("LiberationSans-Regular.ttf", 50);
    //gout.load_font("LiberationSans-Regular.ttf", 15);
}

void screen_clear()
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

void Application::game_process(event ev)
{

}

void Application::event_loop()
{
    event ev;
    int focus = -1;

    while (gin >> ev && ev.keycode != key_escape)
    {
        screen_clear();
        if (_phase == MAIN_MENU) // MAIN MENU PHASE
        {
            if (ev.type == ev_mouse && ev.button == btn_left) {
                for (size_t i=0; i<main_menu.size(); i++) {
                    if (main_menu[i]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        focus = i;
                    }
                }
            }

            if (focus != -1)
            {
                main_menu[focus]->handle(ev);
            }

            screen_clear();

            for (Widget* w: main_menu)
            {
                w->draw();
            }
//            std::cout << rand() << std::endl;
        }

        else if (_phase == GAME) // GAME PHASE
        {
            if (ev.type == ev_mouse && ev.button == btn_left) {
                for (size_t i=0; i<game.size(); i++) {
                    if (game[i]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        focus = i;
                    }
                }
            }

            if (focus != -1)
            {
                game[focus]->handle(ev);
            }

            screen_clear();

//            std::cout << game.size() << std::endl;

            for (Widget* w: game)
            {
                w->draw();
            }

        }

        else if (_phase == GAME_OVER) // GAME OVER SCREEN
        {
            if (ev.type == ev_mouse && ev.button == btn_left) {
                for (size_t i=0; i<gameover_screen.size(); i++) {
                    if (gameover_screen[i]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        focus = i;
                    }
                }
            }

            if (focus != -1)
            {
                gameover_screen[focus]->handle(ev);
            }

            screen_clear();

            for (Widget* w: gameover_screen)
            {
                w->draw();
            }
        }
        gout << refresh;
    }
}



