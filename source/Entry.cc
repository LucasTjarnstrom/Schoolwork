/*
 * Entry.cc
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

string Entry::return_time()
{
  time_t t = time(0);
  tm * now = localtime(&t);
  stringstream ss;
  ss << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-" << (now->tm_mday);
  return ss.str();
}

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
