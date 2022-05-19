#ifndef TILE_H
#define TILE_H

#include "examplecheckbox.hpp"
#include <cmath>

class Tile: public ExampleCheckBox
{
    Turn _type;
public:
    Tile(Application*, int, int, int, int, Phase);
    void draw() override;
    void handle(genv::event) override;
    Phase phase() override;
    void reset();
//    Turn type();
};

#endif // TILE_H
