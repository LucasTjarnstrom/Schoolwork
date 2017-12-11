/*
 * Enemy.cc
 */

#include "Enemy.h"
#include <string>
#include <exception>

using namespace std;

Enemy::Enemy(double xp, double yp, double xs, double ys, string file_name)
    : Character(xp, yp, xs, ys, file_name)
{
    sprite.setOrigin(50,0);
}

sf::Sprite Enemy::draw_this()
{
    sprite.setPosition(x_pos, y_pos);   
    return sprite;
}

void Enemy::move(std::string const & movement)
{
    if (movement == "left")
    {
	x_velocity = -5;
	facing_right = false;
    }
    else if (movement == "right")
    {
	x_velocity = 5;
	facing_right = true;
    }
    else if (movement == "nothing")
        x_velocity = 0;
    else
        throw logic_error("Invalid movement!");
    
    x_pos += x_velocity;
    y_velocity += y_acc; //gravity
    y_pos += y_velocity;
}

void Enemy::jump()
{
    y_velocity = -4;
}
