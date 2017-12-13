/*
 * Entry.cc
 */

#include <SFML/Graphics.hpp>
#include "Entry.h"
#include <sstream>
#include <ostream>

using namespace std;

Entry::Entry()
  : score{}, name{}, date{}
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
  ss << "CoolKille" << " " << "Technomancer" << " " << "-3" << " " << return_time();
  //ss << name << " " << score << " " << return_time();
  return ss.str();
}



