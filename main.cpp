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
    StaticText* _title;
    vector<Tile*> _tiles;
    Button* _start;
    Button* _mmenu;
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

        for (int i=1;i<15*16;i++)
        {
            _tiles.push_back(new Tile(this, 10+(i-1)%15*22,
                                            100+(i-1)/16*22,
                                            20, 20, GAME));
        }
    }
    void reset()
    {
        set_phase(MAIN_MENU);
        for (Tile* i: _tiles)
        {
            i->reset();
        }
    }
};

int main()
{
    MyApp a(800,600);
    a.set_phase(MAIN_MENU);
    a.set_turn(CIRCLE);
    a.event_loop();
    return 0;
}
