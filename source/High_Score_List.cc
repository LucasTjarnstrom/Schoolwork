/*
 * High_Score_List.cc
 */

//#include <SFML/Graphics.hpp>
#include "High_Score_List.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

High_Score_List::High_Score_List()
  : window(sf::VideoMode(1280, 720), "Highscore List"),
  return_button{Button(12,12,0,0,"resources/button_quit.png")} // Placeholder icon for "Return"
{
  window.setFramerateLimit(60);

  caviar.loadFromFile("resources/CaviarDreams.ttf");

  score_text.setFont(caviar);
  score_text.setCharacterSize(30);
  score_text.setStyle(sf::Text::Bold);
  score_text.setColor(sf::Color(255,255,255));
  score_text.setPosition(400,200);

  score_text2.setFont(caviar);
  score_text2.setCharacterSize(30);
  score_text2.setStyle(sf::Text::Bold);
  score_text2.setColor(sf::Color(255,255,255));
  score_text2.setPosition(400,300);
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
  // window.clear();
  show_score();
  splash_screen.get_sprite().setPosition(560,300);
  return_button.get_sprite().setPosition(1,1);
  window.clear(sf::Color(10,110,191));
  window.draw(return_button.get_sprite());
  window.draw(score_text);
  window.draw(score_text2);
  window.display();
}


void High_Score_List::add_entry(unique_ptr<Entry> entry)
{
  int score = entry->get_score();

  for(unsigned i{} ; i < entries.size() ; i++)
    {
      int current_score {};
      current_score = entries.at(i)->get_score();
      if(score > current_score)
	{
	  entries.insert(entries.begin()+i, move(entry));
	  if(entries.size() > 10) 
	    {
	      entries.pop_back();
	    }
	}
    }
}

void High_Score_List::show_score()
{
  save_to_file();
  ifstream infile;
  string line;
  string line2;
  int n{100};
  infile.open("resources/Highscorelist.txt");
  getline(infile,line);
  score_text.setString(line);
  getline(infile,line);
  score_text2.setString(line);
  infile.close();

  /*
  for( unsigned i{} ; i < 3 ; i++ )
    {
      n = n+100;
      getline(infile,line).good();
      score_text.setPosition(400,n);
      score_text.setString(line);
    }
  infile.close();
  */
}

void High_Score_List::save_to_file()
{
  for(unsigned i{} ; i < entries.size() ; i++)
    {
      string new_entry = entries.at(i)->to_string();
      ofstream outfile;
      outfile.open("resources/Highscorelist.txt");
      outfile << new_entry;
      outfile.close();
    }

  // For testing purposes
  ofstream outfile;
  outfile.open("resources/Highscorelist.txt");
  string test = to_string();
  outfile << test << endl;
  string test2 = "CoolKille2 Technodancer -4 2017-12-12";
  outfile << test2 << endl;
  outfile.close();
}

