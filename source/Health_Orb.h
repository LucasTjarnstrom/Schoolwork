/*
 * IDENTIFICATION 
 * File: Health_Orb.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as a health orb in the game loop,
 * i.e. when the player character collides with it they regain 1
 * (eventually) lost health point.
 */

#ifndef HEALTH_ORB_H
#define HEALTH_ORB_H

#include <string>
#include "Environment.h"

class Health_Orb : public Environment
{
public:
    Health_Orb(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;

    void set_health(int);
    int get_health() const;

private:
    int health {};
};

#endif
