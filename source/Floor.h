/*
 * Floor.h
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

};

#endif
