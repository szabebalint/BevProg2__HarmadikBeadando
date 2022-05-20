#include "graphics.hpp"
#include "application.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "spinbox.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "tile.hpp"

using namespace std;
using namespace genv;


class MyApp : public Application
{
protected:
    // ide jonnek a widgetek
    StaticText* _title, *_winner;
    vector<Tile*> _tiles;
    Button* _start;
    Button* _mmenu;
    string _str_winner;
public:
    MyApp(int width, int height) : Application(width,height)
    {
//        gout.load_font("LiberationSans-Regular-ttf", 30);
        // ide jonnek a "new Widget" sorok
        _start = new Button(this, 360, 500, 80, 60, "Indítás", MAIN_MENU, [this](){set_phase(GAME);});
        _mmenu = new Button(this, 360, 500, 80, 60, "Főmenü", GAME, [this](){reset();});
        _title = new StaticText(this, 400-gout.twidth("AMŐBA")/2, 80,
                                          gout.twidth("AMŐBA"),gout.cascent()+gout.cdescent(),
                                          "AMŐBA", MAIN_MENU);
        _winner= new StaticText(this, 300, 300, 200, 50, _str_winner, GAME_OVER);

        for (int i=1;i<15*16;i++)
        {
            _tiles.push_back(new Tile(this, 10+(i-1)%15*22,
                                            100+(i-1)/16*22,
                                            20, 20, GAME));
        }
    }
    void screen_clear() override
    {
        gout << color(0,0,0) << move_to(0,0) << box(800,600);
    }
    void reset()
    {
        set_phase(MAIN_MENU);
        for (Tile* i: _tiles)
        {
            i->reset();
        }
    }
//    void game_process(event ev, int focus, bool win, Turn winner)
//    {
//        vector<size_t> circles;
//        vector<size_t> crosses;

//        for (size_t i=0;i<_tiles.size();i++)
//        {
//            if (_tiles[i]->is_checked() && _tiles[i]->type() == CIRCLE)
//            {
//                circles.push_back(i);
//            }
//            else if (_tiles[i]->is_checked() && _tiles[i]->type() == CROSS)
//            {
//                crosses.push_back(i);
//            }
//        }
//        for (size_t i=0;i<49;i++)
//        {

//        }
//    }
    void event_loop()
    {
        event ev;
        int focus = -1;
//        bool win = 0;
//        Turn winner;

        while (gin >> ev && ev.keycode != key_escape)
        {
//            Tile* last_focused;
            screen_clear();
            if (_phase == MAIN_MENU) // MAIN MENU PHASE
            {
                if (ev.type == ev_mouse && ev.button == btn_left) {
                    for (size_t i=0; i<main_menu.size(); i++) {
                        if (main_menu[i]->is_selected(ev.pos_x, ev.pos_y))
                        {
                            focus = i;
                        }
                    }
                }

                if (focus != -1)
                {
                    main_menu[focus]->handle(ev);
                }

                screen_clear();

                for (Widget* w: main_menu)
                {
                    w->draw();
                }
    //            std::cout << rand() << std::endl;
            }

            else if (_phase == GAME) // GAME PHASE
            {
                if (ev.type == ev_mouse && ev.button == btn_left) {
                    for (size_t i=0; i<game.size(); i++) {
                        if (game[i]->is_selected(ev.pos_x, ev.pos_y))
                        {
                            focus = i;
                            switch (_turn)
                            {
                            case CROSS:
                                set_turn(CIRCLE);
                                break;
                            case CIRCLE:
                                set_turn(CROSS);
                                break;
                            }
                        }
                    }
                }

                if (focus != -1)
                {
                    game[focus]->handle(ev);
                }

                screen_clear();

                for (Widget* w: game)
                {
                    w->draw();
                }
            }

            else if (_phase == GAME_OVER) // GAME OVER SCREEN
            {
                if (ev.type == ev_mouse && ev.button == btn_left) {
                    for (size_t i=0; i<gameover_screen.size(); i++) {
                        if (gameover_screen[i]->is_selected(ev.pos_x, ev.pos_y))
                        {
                            focus = i;
                        }
                    }
                }

                if (focus != -1)
                {
                    gameover_screen[focus]->handle(ev);
                }

                screen_clear();

                for (Widget* w: gameover_screen)
                {
                    w->draw();
                }
            }
            gout << refresh;
        }
    }
};

int main()
{
    MyApp a(800,600);
    a.set_phase(MAIN_MENU);
    a.event_loop();
    return 0;
}
