#ifndef TILE_H
#define TILE_H

#include "examplecheckbox.hpp"
#include <cmath>

class Tile: public ExampleCheckBox
{
    Turn _type;
    int pos_x, pos_y;
public:
    Tile(Application*, int, int, int, int, Phase);
    void draw() override;
    void handle(genv::event) override;

    Phase phase() override;

    void reset();

    void set_pos_x(int);
    void set_pos_y(int);

    int get_pos_x();
    int get_pos_y();

    Turn type();
};

#endif // TILE_H
