/*
 * Enemy.cc
 */

#include "Enemy.h"
#include <string>
#include <exception>
#include <sstream>

using namespace std;

Enemy::Enemy(double xp, double yp, double xs, double ys, string file_name)
    : Character(xp, yp, xs, ys, file_name)
{
    sprite.setOrigin(50,0);

    health_text.setCharacterSize(30);
    health_text.setStyle(sf::Text::Bold);
    health_text.setColor(sf::Color(255, 255, 255));
    health_text.setPosition(400,400);
    health_text.setString("world");
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
    } else if(arg == "floor_wall"){
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
    } else
	throw logic_error("Invalid collision!");

}

sf::Sprite Enemy::attack()
{
    return sprite;
}

sf::Text Enemy::health_to_text()
{
    stringstream ss;
    ss << current_health << "/" << vitality;
    health_text.setString(ss.str());
    health_text.setPosition(x_pos - 30, y_pos - 40);
    
    return health_text;   
}

void Enemy::set_font(sf::Font fn)
{
    health_text.setFont(fn);
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
