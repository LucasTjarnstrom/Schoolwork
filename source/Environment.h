/*
 * Environment.h
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include "Drawable.h"

class Environment : public Drawable
{
public:
    Environment(double,double,double,double, std::string);

    //sf::Sprite draw_this() override;

};

#endif
