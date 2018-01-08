/*
 * IDENTIFICATION 
 * File: Weapon.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as a weapon in the game loop,
 * i.e. increases the player characters attack upon collision.
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Environment.h"

class Weapon : public Environment
{
public:
    Weapon(double,double,double,double, std::string);
    
    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;
    
};

#endif
