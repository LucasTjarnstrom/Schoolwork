/*
 * Wall.h
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

};

#endif
