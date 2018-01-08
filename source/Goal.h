/*
 * IDENTIFICATION 
 * File: Goal.h 
 * Module: Environment
 * 
 * DESCRIPTION 
 * This class acts as a goal in the game loop,
 * i.e. when the player character enters the goal they win the game.
 */

#ifndef GOAL_H
#define GOAL_H

#include <string>
#include "Environment.h"

class Goal : public Environment
{
 public:
  Goal(double,double,double,double,std::string);
  
  sf::Sprite draw_this() override;
  void is_colliding(std::string) override;
};

#endif
