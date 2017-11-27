/*
 * Drawable.cc
 */

#include "Drawable.h"

Drawable::Drawable(int xp, int yp, int xs, int ys)
    : x_pos{xp}, y_pos{yp}, x_size{xs}, y_size{ys}
{
}                
    
// Position
int Drawable::get_x_pos() const
{
    return x_pos;
}

void Drawable::set_x_pos(int xp)
{
    x_pos = xp;
}

int Drawable::get_y_pos() const
{
    return y_pos;
}

void Drawable::set_y_pos(int yp)
{
    y_pos = yp;
}

// Velocity, acceleration
int Drawable::get_x_velocity() const
{
    return x_velocity;
}

void Drawable::set_x_velocity(int xv)
{
    x_velocity = xv;
}

int Drawable::get_y_velocity() const
{
    return y_velocity;
}

void Drawable::set_y_velocity(int yv)
{
    y_velocity = yv;
}

int Drawable::get_y_acc() const
{
    return y_acc;
}

void Drawable::set_y_acc(int ya)
{
    y_acc = ya;
}

// Size
int Drawable::get_x_size() const
{
    return x_size;
}

void Drawable::set_x_size(int xs)
{
    x_size = xs;
}

int Drawable::get_y_size() const
{
    return y_size;
}
  
void Drawable::set_y_size(int ys)
{
    y_size = ys;
}
