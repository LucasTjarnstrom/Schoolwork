/*
 * IDENTIFICATION 
 * File: Attack.h 
 * Module: Character
 * 
 * DESCRIPTION 
 * This class handles the attack ability for all characters.
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
