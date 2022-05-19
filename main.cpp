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
    Tile* t;

public:
    MyApp(int width, int height):Application(width,height)
    {
        // ide jonnek a "new Widget" sorok
        t = new Tile(this, 100, 100, 20, 20, GAME);
    }
};

int main()
{
    MyApp a(800,600);
    a.set_phase(GAME);
    a.set_turn(CROSS);
    a.event_loop();
    return 0;
}
