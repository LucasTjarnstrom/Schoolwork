/*
 * Start_Menu.h
 */

#ifndef START_MENU_H
#define START_MENU_H

#include "Button.h"
#include <string>

class Start_Menu
{
 public:
  Start_Menu();
  std::string run();

 private:
  std::string process_events();
  void handle_player_input(sf::Mouse::Button button);
  void render();

  sf::RenderWindow window {};
  Button start_button {};
  Button continue_button {};
  Button high_score_button {};
  Button quit_button {};
};

#endif
