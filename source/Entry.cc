/*
 * Entry.cc
 */

#include <SFML/Graphics.hpp>
#include "Entry.h"
#include <stringstream>

using namespace std;

Entry::Entry()
  : score{}, name{}, date{}
{
  date = return_time();
}


string Entry::return_time()
{
  time_t t = time(0);
  tm * now = localtime(&t);
  stringstream ss;
  ss << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-" << (now->tm_mday);
  return ss;
}

string Entry::to_string()
{
  stringstream ss;
  ss << "CoolKille" << " " << "Technomancer" << " " << "-3" << " " << return_time();
  return ss;
}
