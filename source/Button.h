/*
 * IDENTIFICATION 
 * File: Button.h 
 * Module: Menu
 * 
 * DESCRIPTION 
 * This class handles the buttons for all menues.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.h"
#include <string>

class Button : public Drawable
{
public:
    Button() = default;
    Button(double, double, double, double, std::string);
    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;
};


#endif
