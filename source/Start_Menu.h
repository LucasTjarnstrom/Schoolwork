#ifndef START_MENU_H
#define START_MENU_H

#include "Button.h"

class Start_Menu
{
 public:
  Start_Menu();
  void run();

 private:
  void process_events();
  void handle_player_input(sf::Mouse::Button button);
  void render();
  void start_game();
  void continue_game();
  void show_high_score_list();
  void quit();

  sf::RenderWindow window {};
  Button start_button {};
};

#endif
