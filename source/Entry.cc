/*
 * Entry.cc
 This class handles the entries to the highscore list.
 */

#include <SFML/Graphics.hpp>
#include "Entry.h"
#include <sstream>
#include <ostream>

using namespace std;

Entry::Entry(string na, int sc, string da)
  : name {na}, score{sc}, date{da}
{
}

// Returns the current date
string Entry::return_time()
{
  time_t t = time(0);
  tm * now = localtime(&t);
  stringstream ss;
  ss << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-" << (now->tm_mday);
  return ss.str();
}

// Reformats name, score and time variables into a single string
string Entry::to_string()
{
  stringstream ss;
  ss << name << " " << score << " " << return_time();
  return ss.str();
}

int Entry::get_score()
{
  return score;
}
