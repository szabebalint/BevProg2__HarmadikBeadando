#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgets.hpp"
#include <string>


class StaticText: public Widget
{
protected:
    std::string _s;
public:
    StaticText(Application*, int, int, int, int, std::string, Phase);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    Phase phase() override;
};

#endif // STATICTEXT_HPP
