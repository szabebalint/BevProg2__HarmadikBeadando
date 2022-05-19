#ifndef TILE_H
#define TILE_H

#include "examplecheckbox.hpp"
#include <cmath>

class Tile: public ExampleCheckBox
{
    Turn _type;
    Phase _belongs_to;
public:
    Tile(Application*, int, int, int, int);
    void draw() override;
    void handle(genv::event) override;
    Turn type();
};

#endif // TILE_H
