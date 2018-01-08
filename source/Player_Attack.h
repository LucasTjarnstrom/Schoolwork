/*
 * IDENTIFICATION 
 * File: Player_Attack.h 
 * Module: Character
 * 
 * DESCRIPTION
 * This class handles the attack ability for the player character. 
 */

#ifndef PLAYER_ATTACK_H
#define PLAYER_ATTACK_H

#include <string>
#include "Attack.h"

class Player_Attack : public Attack
{
public:
    Player_Attack() = default;
    Player_Attack(double,double,double,double, std::string);
    
    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;

};

#endif
