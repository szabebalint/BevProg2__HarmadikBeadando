#include "tile.hpp"

using namespace genv;

bool in_radius(int x, int y, int u, int v)
{
    int c = sqrt((pow(x-u,2)+pow(y-v,2)));
    return c >=6 && c <= 8;
}

Tile::Tile(Application* parent, int x, int y, int sx, int sy, Phase p):
    ExampleCheckBox(parent,x,y,sx,sy,p)
{
    _checked = false;
    _phase = GAME;
}

Phase Tile::phase()
{
    return _phase;
}

void Tile::reset()
{
    _checked = false;
}

void Tile::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left && !_checked && is_selected(ev.pos_x,ev.pos_y))
        {
            _type = _parent->turn();
            _checked = true;
        }
    }
}

void Tile::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (_checked)
    {
        if (_type == CROSS)
        {
            gout << color(255,255,255)
                 << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8)
                 << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8)
                 << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8)
                 << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
        }
        else if (_type == CIRCLE)
        {
            for (int i=_x;i<_x+_size_x;i++)
            {
                for (int j=_y;j<_y+_size_y;j++)
                {
                    if (in_radius(i,j,_x+_size_x/2, _y+_size_y/2))
                    {
                        gout << color(255,255,255) << move_to(i,j) << dot;
                    }
                }
            }
        }
    }
}
