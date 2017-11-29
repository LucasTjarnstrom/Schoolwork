/*
 * Drawable.cc
 */

#include "Drawable.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;

Drawable::Drawable(double xp, double yp, double xs, double ys, string file_name)
    : x_pos{xp}, y_pos{yp}, x_size{xs}, y_size{ys}
{
    try
    {
	texture.loadFromFile(file_name, sf::IntRect(0,0,x_size,y_size));
    }
    catch (exception& e)
    {
	cout << e.what() << endl;
    }

    sprite.setTexture(texture);

}                
    
// Position
double Drawable::get_x_pos() const
{
    return x_pos;
}

void Drawable::set_x_pos(double xp)
{
    x_pos = xp;
}

double Drawable::get_y_pos() const
{
    return y_pos;
}

void Drawable::set_y_pos(double yp)
{
    y_pos = yp;
}

// Velocity, acceleration
double Drawable::get_x_velocity() const
{
    return x_velocity;
}

void Drawable::set_x_velocity(double xv)
{
    x_velocity = xv;
}

double Drawable::get_y_velocity() const
{
    return y_velocity;
}

void Drawable::set_y_velocity(double yv)
{
    y_velocity = yv;
}

double Drawable::get_y_acc() const
{
    return y_acc;
}

void Drawable::set_y_acc(double ya)
{
    y_acc = ya;
}

// Size
double Drawable::get_x_size() const
{
    return x_size;
}

void Drawable::set_x_size(double xs)
{
    x_size = xs;
}

double Drawable::get_y_size() const
{
    return y_size;
}
  
void Drawable::set_y_size(double ys)
{
    y_size = ys;
}

sf::Sprite& Drawable::get_sprite()
{
    return sprite;
}
