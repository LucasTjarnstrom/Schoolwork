/*
 * Entry.h
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
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
