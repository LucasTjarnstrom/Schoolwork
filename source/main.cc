#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "High_Score_List.h"
#include "Start_Menu.h"

using namespace std;

// The "main" game loop. Returns a string to indicate which menu item the user chose.
// The while loop runs until the user exits through the main menu.

int main()
{
  pair <string,bool> user_choice_and_quit{};
  pair <string,int> name_and_score{};
  while(!user_choice_and_quit.second)
    {
      Start_Menu start_menu {};
      user_choice_and_quit = start_menu.run();
      Game game {};
      name_and_score = game.run(user_choice_and_quit.first);
      if (name_and_score.second != 0 && name_and_score.first != "")
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
