#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    bool _checked;
public:
    ExampleCheckBox(Application*, int, int, int, int, Phase);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool is_checked();
    Phase phase() override;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
