/*
 * IDENTIFICATION 
 * File: Ceiling.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as ceiling in the game loop.
 */

#ifndef CEILING_H
#define CEILING_H

#include <string>
#include "Environment.h"

class Ceiling : public Environment
{
public:
    Ceiling(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;
};

#endif
