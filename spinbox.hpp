#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "widgets.hpp"
#include "application.hpp"

class Spinbox : public Widget
{
protected:
    int _number=0, _min, _max;
    //bool is_focused;
public:
    Spinbox(Application* parent, int x, int y, int sx, int sy, Phase p, int min, int max);
    void increase(int); // setter szam valtoztatasahoz
    void decrease(int);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    Phase phase() override;
    int get_number();
};

#endif // SPINBOX_HPP
