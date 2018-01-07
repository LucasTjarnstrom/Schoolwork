/*
 * Attack.h
 This class handles the attack ability for characters.
 */

#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "Drawable.h"

class Attack : public Drawable
{
public:
    Attack() = default;
    Attack(double,double,double,double, std::string);

};

#endif
