/*

 * Start_Menu.h
 */

#ifndef START_MENU_H
#define START_MENU_H

class Start_Menu : public Level
{
public:
  Start_Menu() = default; // default constructor
  virtual ~Start_Menu() = default; // destructor

  Start_Menu(Start_Menu const& it); // copy constructor
  Start_Menu(Start_Menu && it); // move constructor
  Start_Menu& operator=(Start_Menu const& it); // copy assignment
  Start_Menu& operator=(Start_Menu && it); // move assignment

  void start_game();
  void continue();
  void show_high_score_list();
  void quit();
};

#endif