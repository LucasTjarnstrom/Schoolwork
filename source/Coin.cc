/*
 * Coin.cc
 */

#include "Coin.h"
#include <string>

using namespace std;

Coin::Coin(double xp, double yp, double xs, double ys, string file_name)
    : Environment(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Coin::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    return sprite;
}

void Coin::is_colliding(string)
{
    return;
}

void Coin::set_score(int sc)
{
    score = sc;
}

int Coin::get_score() const
{
    return score;
}
