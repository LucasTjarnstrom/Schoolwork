/*
 * IDENTIFICATION 
 * File: Floor.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as floor in the game loop.
 */

#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include "Environment.h"

class Floor : public Environment
{
public:
    Floor(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;
};

#endif
