/*
 * Character.cc
 */

#include "Character.h"
#include <string>

using namespace std;

Character::Character(int vit)
    : vitality{vit}
{
}

Character::Character(double xp, double yp, double xs, double ys, string file_name)
    : Drawable(xp, yp, xs, ys, file_name)
{
}

void Character::set_vitality(int vit)
{
    vitality = vit;
}

int Character::get_vitality() const
{
    return vitality;
}

void Character::set_current_health(int health)
{
    current_health = health;
}


int Character::get_current_health() const
{
    return current_health;
}

void Character::set_facing_right(bool fr)
{
    facing_right = fr;
}

bool Character::get_facing_right()
{
    return facing_right;
}

