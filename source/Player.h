/*
 * Player.h
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>

class Player : public Character
{
public:
    Player() = default;           // default constructor
    Player(int);                  // constructor

    // Setters and getters do not have to be virtual
    //void set_vitality(int);
    //int get_vitality() const;

    //void set_current_health(int);
    //int get_current_health() const;

    //void jump() override;
    //void attack() override;
    //void move(std::string const &) override;
    //void take_damage(int) override;

};

#endif 

