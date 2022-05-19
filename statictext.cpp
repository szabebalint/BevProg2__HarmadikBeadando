#include "statictext.hpp"
#include "graphics.hpp"
using namespace std;
using namespace genv;

StaticText::StaticText(Application* parent, int x, int y, int sx, int sy, string s, Phase p)
    :Widget(parent,x,y,sx,sy,p), _s(s)
{
}

void StaticText::draw()
{
    gout.load_font("LiberationSans-Regular.ttf", 20);

    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y)
         << move_to(_x + 5, _y + 5)
         << color(0,0,0) << text(_s);
}

void StaticText::handle(event ev)
{}

Phase StaticText::phase()
{
    return _phase;
}
