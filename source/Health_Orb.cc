/*
 * Health_Orb.cc
 */

#include "Health_Orb.h"
#include <string>

using namespace std;

Health_Orb::Health_Orb(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Health_Orb::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Health_Orb::is_colliding(string)
{
    return;
}

void Health_Orb::set_health(int hel)
{
    health = hel;
}

int Health_Orb::get_health() const
{
    return health;
}
