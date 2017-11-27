/*
 * Character.cc
 */

#include "Character.h"

Character::Character(int vit)
    : vitality{vit}
{
}

Character::Character(int xp, int yp, int xs, int ys)
    : Drawable(xp, yp, xs, ys)
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
