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
    
    if(faced_right != facing_right) 
    	sprite.scale(-1.f,1.f);   
    else
	sprite.scale(1.f,1.f);
    faced_right = facing_right;
    
    return sprite;
}

void Enemy::move(std::string const & movement)
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

void Enemy::jump()
{
    y_velocity = -4;
}

void Enemy::is_colliding(string arg)
{
    if(arg == "floor")
    {
	y_velocity = -0.2;
    } else if(arg == "wall"){
      if(get_facing_right())
	  {
	    x_pos -= 5;
	    set_facing_right(false);
	  }
	else
	  {
	    x_pos += 5;
	    set_facing_right(true);
	  }
    } else if(arg == "floor_wall")
      if(get_facing_right())
	  {
	    x_pos -= 5;
	    set_facing_right(false);
	  }
	else
	  {
	    x_pos += 5;
	    set_facing_right(true);
	  }
}

sf::Sprite Enemy::attack()
{
    return sprite;
}

void Enemy::set_facing_right(bool b)
{
  facing_right = b;
  return;
}

bool Enemy::get_facing_right()
{
  return facing_right;
}
