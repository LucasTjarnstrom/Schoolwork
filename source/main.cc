#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start_Menu.h"

using namespace std;

int main()
{
  Start_Menu start_menu {};
  string user_choice = start_menu.run();
  Game game {};
  pair <string,int> name_and_score = game.run(user_choice);
  if (name_and_score.second != 0)
    {
      //Lägg in name_and_score.first (namn) och name_and_score.second (poäng) i en entry.
      cout << "Spelare: " << name_and_score.first << "\nPoäng: " << name_and_score.second << endl;
    }
  return 0;
}
