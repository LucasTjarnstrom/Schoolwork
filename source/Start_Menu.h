/*
 * Start_Menu.h
 This class handles the start menu.
 */

#ifndef START_MENU_H
#define START_MENU_H

#include "Button.h"
#include "High_Score_List.h"
#include <string>

class Start_Menu
{
 public:
  Start_Menu();
  std::pair <std::string,bool> run();
  
 private:
  std::string process_events();
  void handle_player_input(sf::Mouse::Button button);
  void render();
  
  sf::RenderWindow window {};
  Button start_button {};
  Button high_score_button {};
  Button quit_button {};
  
  sf::Texture background_texture {};
  sf::Sprite background_sprite {};
};

#endif
