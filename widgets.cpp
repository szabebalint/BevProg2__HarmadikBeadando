#include "widgets.hpp"
#include "graphics.hpp"

Widget::Widget(Application* parent, int x, int y, int sx, int sy):
    _parent(parent), _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::is_selected(int mx, int my)
{
    return mx > _x && mx < _x+_size_x &&
           my > _y && my < _y+_size_y;
}
