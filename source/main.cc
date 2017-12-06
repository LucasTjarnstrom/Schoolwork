#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start_Menu.h"

using namespace std;

int main()
{
  Start_Menu start_menu {};
  string user_choice = start_menu.run();
  Game game {};
  game.run();
  return 0;
}
