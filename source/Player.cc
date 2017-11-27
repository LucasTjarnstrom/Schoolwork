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

Player::Player(int xp, int yp, int xs, int ys, string file_name)
    : Character(xp, yp, xs, ys, file_name)
{
}
