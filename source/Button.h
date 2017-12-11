/*

 * Button.h
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
    void is_colliding() override;
};


#endif
