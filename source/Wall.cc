/*
 * Wall.cc
 */

#include "Wall.h"
#include <string>

using namespace std;

Wall::Wall(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Wall::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

