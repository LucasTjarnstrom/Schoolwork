/*
 * Goal.h
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
