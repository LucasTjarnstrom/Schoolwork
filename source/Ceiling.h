/*
 * Ceiling.h
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
    void is_colliding() override;
};

#endif
