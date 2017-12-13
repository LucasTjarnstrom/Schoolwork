/*
 * Floor.cc
 */

#include "Floor.h"
#include <string>

using namespace std;

Floor::Floor(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Floor::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Floor::is_colliding(string)
{
    return;
}
