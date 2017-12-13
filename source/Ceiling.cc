/*
 * Ceiling.cc
 */

#include "Ceiling.h"
#include <string>

using namespace std;

Ceiling::Ceiling(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Ceiling::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Ceiling::is_colliding()
{
    return;
}
