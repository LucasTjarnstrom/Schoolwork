#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "High_Score_List.h"
#include "Start_Menu.h"

using namespace std;

int main()
{
  string user_choice{};
  pair <string,int> name_and_score{};
  bool quit{false};
  while(!quit)
    {
      Start_Menu start_menu {};
      user_choice = start_menu.run();
      Game game {};
      name_and_score = game.run(user_choice);
      if (name_and_score.second != 0)
	{
	  Entry entry {};
	  entry.name = name_and_score.first;
	  entry.score = name_and_score.second;
	  unique_ptr<Entry> temp = make_unique<Entry>(entry);
	  High_Score_List highscore_list {};
	  highscore_list.add_entry(move(temp));
	}
    }
  return 0;
}
