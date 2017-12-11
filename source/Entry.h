/*
 * Entry.h
 */

#ifndef ENTRY_H
#define ENTRY_H

#include "High_Score_List.h"
#include <string>

class Entry : public High_Score_List
{
 public:
  Entry();

  std::string name {};
  std::string date {};
  int score {};

  std::string return_time();

  int get_score();
  std::string to_string();

 protected:

};

#endif
