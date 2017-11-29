/*

 * High_Score_List.h
 */

#ifndef HIGH_SCORE_LIST_H
#define HIGH_SCORE_LIST_H

#include <string>

class High_Score_List : public Level
{
public:
  High_Score_List() = default; // default constructor
  High_Score_List(vector<Entry*>); // constructor
  virtual ~High_Score_List() = default; // destructor

  High_Score_List(High_Score_List const& it); // copy constructor
  High_Score_List(High_Score_List && it); // move constructor
  High_Score_List& operator=(High_Score_List const& it); // copy assignment
  High_Score_List& operator=(High_Score_List && it); // move assignment

  void show_score();
  void add_entry(Entry*);
  void save_to_file(std::string);
  void load_to_file(std::string);

protected:
  entries vector<Entry*>;
  
};

#endif 