/*
 * Entry.h
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
public:
  Entry() = default;
    Entry(std::string, int, std::string);

    std::string name {};
    int score {};
    std::string date {};
    
    std::string return_time();

    int get_score();
    std::string to_string();

protected:

};

#endif
