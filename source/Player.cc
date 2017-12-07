/*
 * Player.cc
 */

#include "Player.h"
#include <string>
#include <exception>
#include <iostream>

using namespace std;

Player::Player(int vit)
    : Character(vit)
{
}

Player::Player(double xp, double yp, double xs, double ys, string file_name)
    : Character(xp, yp, xs, ys, file_name)
{
    sprite.setOrigin(50,0);
}

sf::Sprite Player::draw_this()
{
    sprite.setPosition(x_pos, y_pos);
    
    if(faced_right != facing_right) //funkar inte korrekt
    	sprite.scale(-1.f,1.f);       // bör kanske implementera hjälpfunktioner flip och unflip
        
	// https://en.sfml-dev.org/forums/index.php?topic=7572.0
    else
	sprite.scale(1.f,1.f);
    faced_right = facing_right;
    
    return sprite;
}

void Player::move(std::string const & movement)
{
    if (movement == "left")
    {
	x_velocity = -1;
	facing_right = false;
    }
    else if (movement == "right")
    {
	x_velocity = 1;
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

void Player::jump()
{
    y_velocity = -4;
}
