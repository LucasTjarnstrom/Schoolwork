/*
 * Drawable.cc
 */

#include "Drawable.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;

Drawable::Drawable(int xp, int yp, int xs, int ys, string file_name)
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

sf::Sprite Drawable::get_sprite()
{
    return sprite;
}
