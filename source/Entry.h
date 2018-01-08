/*
 * IDENTIFICATION 
 * File: Entry.h 
 * Module: Menu
 * 
 * DESCRIPTION
 * This class handles the entries to the highscore list. 
 * The entries contain the date, name and score which is 
 * saved after a user completes the game.
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
 public:
  Entry() = default;
  Entry(std::string, int, std::string);

  int get_score();
  std::string to_string();
  std::string name {};
  int score {};
  
 protected:
  std::string date {};
  std::string return_time();
  
};

#endif
