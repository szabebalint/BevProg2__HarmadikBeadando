#include "spinbox.hpp"

#include <sstream>
//#include <iostream>
using namespace genv;

Spinbox::Spinbox(Application* parent, int x, int y, int sx, int sy, int min, int max):
    Widget(parent, x, y, sx, sy), _min(min), _max(max)
{}

void Spinbox::draw()
{
    std::stringstream ss;
    ss << _number;

    // widget kirajzolása
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y)
         << color(200,200,255)
         << move_to(_x+_size_x*0.8, _y) << box(_size_x*0.2, _size_y)
         << move_to(_x+_size_x*0.2, _y+_size_y/2) << color(255,255,255) << line_to(_x+_size_x, _y+_size_y/2-2);

    // szám kiírása
    gout << move_to(_x+10, _y+_size_y*0.67) << color(0,0,0)
         << text(ss.str());

    gout << color(255,255,255) << move_to(_x+_size_x*0.85, _y+_size_y/2-gout.cdescent())
         << text('+')
         << color(255,255,255) << move_to(_x+_size_x*0.85, _y+_size_y-gout.cdescent())
         << text('-');
}

void Spinbox::increase(int x)
{
    if (_number+x >= _min && _number+x <= _max)
    {
        _number += x;
    }
}
void Spinbox::decrease(int x)
{
    if (_number-x >= _min && _number-x <= _max)
    {
        _number -= x;
    }
}
void Spinbox::handle(event ev)
{
    //std::cout << "anyad" << std::endl;
    if (ev.type == ev_key)
    {
        if (ev.keycode == 82)
        {
            increase(1);
        }
        else if (ev.keycode == 75)
        {
            increase(10);
        }
        else if (ev.keycode == 81)
        {
            decrease(1);
        }
        else if (ev.keycode == 78)
        {
            decrease(10);
        }
//        std::cout << _number << std::endl;
    }
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left && ev.pos_x > _x+_size_x*0.8 && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y/2)
        {
            increase(1);
        }
        if (ev.button == btn_left && ev.pos_x > _x+_size_x*0.8 && ev.pos_x < _x+_size_x && ev.pos_y > _y+_size_y/2 && ev.pos_y < _y+_size_y)
        {
            decrease(1);
        }
    }
}
