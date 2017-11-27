/*
 * Player.cc
 */

#include "Player.h"

Player::Player(int vit)
    : Character(vit)
{
}

Player::Player(int xp, int yp, int xs, int ys)
    : Character(xp, yp, xs, ys)
{
}
