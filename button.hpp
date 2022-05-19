#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgets.hpp"

class Button : public Widget
{
protected:
    std::function<void()> _f;
    std::string _title;
    Phase _belongs_to;
public:
    Button(Application*, int, int, int, int, std::string, Phase, std::function<void()>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    bool is_pressed = 0;
    virtual void action();
};

#endif // BUTTON_HPP
