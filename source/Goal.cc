/*
 * Goal.cc
 */

#include "Goal.h"
#include <string>

using namespace std;

Goal::Goal(double xp, double yp, double xs, double ys, string file_name)
  : Environment(xp,yp,xs,ys,file_name)
{
}

sf::Sprite Goal::draw_this()
{
  sprite.setPosition(x_pos,y_pos);
  return sprite;
}

void Goal::is_colliding(string)
{
  return;
}
