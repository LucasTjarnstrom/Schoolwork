/*
 * Weapon.cc
 */

#include "Weapon.h"
#include <string>

using namespace std;

Weapon::Weapon(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Weapon::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Weapon::is_colliding(string)
{
    return;
}
