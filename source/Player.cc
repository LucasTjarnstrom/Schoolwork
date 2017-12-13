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
    : Character(xp, yp, xs, ys, file_name),
      attack_(0,0,0,0,"resources/player_attack.png")
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

void Player::jump()
{
    if(jump_counter > 0)
    {
	y_velocity = -4;	
	jump_counter--;
    }
}

void Player::set_weapon_damage(int dm)
{
    weapon_damage = dm;
}

int Player::get_weapon_damage() const
{
    return weapon_damage;
}

void Player::is_colliding(string arg)
{
  if(arg == "floor")
    {
      y_velocity = -0.1;
      jump_counter = 1;
    }
  else if(arg == "wall")
    {
      if(facing_right)
	x_pos -= 5;
      else
	x_pos += 5;
    }
  else if(arg == "floor_wall")
    {
      if(facing_right)
	x_pos -= 5;
      else
	x_pos += 5;
    }
  else if(arg == "ceiling")
    {
      y_pos += 5;
      y_velocity = 1;
    }
}

sf::Sprite Player::attack()
{
    if(facing_right)
	attack_.get_sprite().setPosition(x_pos + 50, y_pos+25);
    else
	attack_.get_sprite().setPosition(x_pos - 100, y_pos+25);
    
    return attack_.get_sprite();
}
