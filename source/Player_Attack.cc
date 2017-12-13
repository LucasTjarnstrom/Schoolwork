/*
 * Player_Attack.cc
 */

#include "Player_Attack.h"
#include <string>

using namespace std;

Player_Attack::Player_Attack(double xp, double yp, double xs, double ys, string file_name)
    : Attack(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Player_Attack::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Player_Attack::is_colliding(string)
{
    return;
}
