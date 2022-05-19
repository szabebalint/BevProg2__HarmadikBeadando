#include "graphics.hpp"
#include "application.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "spinbox.hpp"
#include "statictext.hpp"

using namespace std;
using namespace genv;


class MyApp : public Application
{
protected:
    // ide jonnek a widgetek

public:
    MyApp(int width, int height):Application(width,height)
    {
        // ide jonnek a "new Widget" sorok

    }
};

int main()
{
    MyApp a(800,600);
    a.event_loop();
    return 0;
}
