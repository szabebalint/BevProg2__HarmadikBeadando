#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    bool _checked;
public:
    ExampleCheckBox(Application*, int, int, int, int);
    virtual void draw() = 0;
    virtual void handle(genv::event ev);
    virtual bool is_checked() = 0;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
