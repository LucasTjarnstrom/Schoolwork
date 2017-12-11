/*
 * High_Score_List.cc
 */

#include <SFML/Graphics.hpp>
#include "High_Score_List.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

High_Score_List::High_Score_List()
  : window(sf::VideoMode(1280, 720), "Highscore List"),
    splash_screen{Button(12,12,0,0,"resources/highscores.png")},
  return_button{Button(12,12,0,0,"resources/button_quit.png")} // Placeholder icon for "Return"
{
  window.setFramerateLimit(60);
}

void High_Score_List::run()
{
  while( window.isOpen() )
    {
      process_events();
      render();
    }
}

void High_Score_List::process_events()
{
  sf::Event event;
  while (window.pollEvent(event))
    {
      switch(event.type)
	{
	case sf::Event::Closed:
	  {
	    return;
	  }
	case sf::Event::KeyPressed:
	    if (event.key.code == sf::Keyboard::Escape) 
	    {
	      window.close();
	    } 
	case sf::Event::MouseButtonPressed:
	  {
	    if (event.mouseButton.button == sf::Mouse::Left)
	      {
		if(sf::Mouse::getPosition(window).x > 1 && sf::Mouse::getPosition(window).x < 100 &&
		   sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 100)
		  {
		    window.close();
		    Start_Menu start_menu {};
		    string user_choice = start_menu.run();
		    Game game {};
		    game.run(user_choice);
		  }
	      }
	    break;
	  }
	default:
	  break;
	}
    }
}

void High_Score_List::render()
{
  splash_screen.get_sprite().setPosition(560,300);
  return_button.get_sprite().setPosition(1,1);
  window.clear(sf::Color(10,110,191));
  window.draw(splash_screen.get_sprite());
  window.draw(return_button.get_sprite());
  window.display();
}


void High_Score_List::add_entry(unique_ptr<Entry> entry)
{
  //entries.push_back(move(entry));
  
  string new_entry = entry->to_string();

  ofstream outfile;
  outfile.open("Highscorelist.txt");
  outfile << new_entry;

}

void High_Score_List::show_score()
{

  ifstream infile;
  infile.open("Highscorelist.txt");

}
