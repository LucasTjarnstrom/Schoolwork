/*
 * Player.cc
 */

#include "Player.h"
#include <string>

using namespace std;

Player::Player(int vit)
    : Character(vit)
{
}

Player::Player(double xp, double yp, double xs, double ys, string file_name)
    : Character(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Player::draw_this()
{
    return sprite;
}
