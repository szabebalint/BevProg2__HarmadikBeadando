#include "button.hpp"

using namespace genv;

Button::Button(Application* parent, int x, int y, int sx, int sy, std::string title, Phase p, std::function<void()> f) :
    Widget(parent,x,y,sx,sy,p)
{
    _title = title;
    _f = f;
}

void Button::draw()
{
    gout.load_font("LiberationSans-Regular.ttf", 18);
    // gomb rajzolasa
    gout << color(255,255,255)
         << move_to(_x,_y) << box(_size_x, _size_y)
         << color(200,200,255)
         << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4);
    // title
    gout << color(0,0,0)
         << move_to(_x+(_size_x-gout.twidth(_title))/2, _y+_size_y-gout.cascent()-gout.cdescent())
         << text(_title);
}

void Button::action()
{
    _f();
}

void Button::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y))
        {
            action();
        }
    }
}

Phase Button::phase()
{
    return _phase;
}
