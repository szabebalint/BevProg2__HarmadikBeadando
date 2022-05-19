#include "application.hpp"


using namespace genv;

void Application::ev_loop(event ev, int focus)
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
    gout << refresh;
}


void screen_clear()
{
    gout << move_to(0,0) << color(0,0,0) << box(800, 600);
}

Turn Application::turn()
{
    return _turn;
}

Phase Application::phase()
{
    return _phase;
}

Application::Application(int width, int height)
{
    gout.open(width, height);
    //gout.load_font("LiberationSans-Regular.ttf", 15);
}

void Application::add_widget(Widget* w)
{

}

void Application::event_loop()
{
    event ev;
    int focus = -1;

    while (gin >> ev && ev.keycode != key_escape)
    {
        if (_phase == MAIN_MENU)
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
            gout << refresh;
        }
        else if (_phase == GAME)
        {

        }
    }
}



