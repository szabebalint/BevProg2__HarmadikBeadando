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
    Spinbox* size_setter;
    Button* _start;
    Button* _mmenu;
public:
    MyApp(int width, int height) : Application(width,height)
    {
        // ide jonnek a "new Widget" sorok
        _start = new Button(this, 100, 500, 80, 60, "Start", MAIN_MENU, [this](){set_phase(GAME);});
        _mmenu = new Button(this, 200, 500, 80, 60, "Return", GAME, [this](){set_phase(MAIN_MENU);});
        size_setter = new Spinbox(this, 250, 270, 300, 60, MAIN_MENU, 15, 30);

        for (int i=1;i<15*15;i++)
        {
            _tiles.push_back(new Tile(this, 10+(i-1)%16*22,
                                            100+(i-1)/16*22,
                                            20, 20, GAME));
            cout << i << endl;
        }

    }
};

int main()
{
    MyApp a(800,600);
    a.set_phase(MAIN_MENU);
    a.set_turn(CROSS);
    a.event_loop();
    return 0;
}
