#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgets.hpp"
#include <string>


class StaticText: public Widget
{
protected:
    std::string _s;
public:
    StaticText(Application*, int, int, int, int, std::string);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif // STATICTEXT_HPP
