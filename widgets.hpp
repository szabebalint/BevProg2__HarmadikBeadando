#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"
#include "application.hpp"
#include <functional>

class Widget
{
protected:
    Application* _parent;
    int _x, _y, _size_x, _size_y;
    Phase _phase;
    //bool in_focus = 0;
public:
    Widget(Application*, int x, int y, int sx, int sy, Phase p);
    virtual bool is_selected(int mx, int my);
    //virtual bool is_focused();
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual Phase phase();
};

#endif // WIDGETS_HPP
