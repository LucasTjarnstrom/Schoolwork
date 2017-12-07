/*
 * High_Score_List.h
 */

#ifndef HIGH_SCORE_LIST_H
#define HIGH_SCORE_LIST_H

#include "Game.h"
#include "Start_Menu.h"
#include "Button.h"
#include <string>
#include <memory>

class High_Score_List : public Game
{
public:
  High_Score_List(); // default constructor
  //High_Score_List(std::unique_ptr<vector<Entry>>); // constructor

  void run();

  // High_Score_List(High_Score_List const& it); // copy constructor
  // High_Score_List(High_Score_List && it); // move constructor
  // High_Score_List& operator=(High_Score_List const& it); // copy assignment
  // High_Score_List& operator=(High_Score_List && it); // move assignment

  //void show_score();
  //void add_entry(std::unique_ptr<Entry>);
  //void save_to_file(std::string);
  //void load_to_file(std::string);

protected:
  //entries vector<std::unique_ptr<Entry>>;

  sf::RenderWindow window{};
  Button splash_screen {};
  Button return_button {};

  void render();
  void process_events();
};

#endif 
