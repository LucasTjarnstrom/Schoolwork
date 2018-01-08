/*
 * IDENTIFICATION 
 * File: Wall.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as wall in the game loop.
 */

#ifndef WALL_H
#define WALL_H

#include <string>
#include "Environment.h"

class Wall : public Environment
{
public:
    Wall(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;

};

#endif
