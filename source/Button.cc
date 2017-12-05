#include "Button.h"
#include <string>

using namespace std;

Button::Button(double xp, double yp, double xs, double ys, string file_name)
  : Drawable(xp, yp, xs, ys, file_name)
{
}

sf::Sprite Button::draw_this()
{
  return sprite;
}
