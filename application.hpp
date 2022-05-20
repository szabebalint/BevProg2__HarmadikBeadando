#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Widget;

enum Phase
{
    MAIN_MENU,
    GAME,
    GAME_OVER
};

enum Turn
{
    CIRCLE,
    CROSS
};

class Application
{
protected:
    Phase _phase;
    Turn _turn;
    std::vector<Widget*> main_menu;
    std::vector<Widget*> game;
    std::vector<Widget*> gameover_screen;
public:
    Application(int, int);
    void event_loop();
    void screen_clear();
//    void game_process(genv::event);
    void add_widget(Widget*);
    Phase phase();
    Turn turn();
    void set_phase(Phase);
    void set_turn(Turn);
};

#endif // APPLICATION_HPP
