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
  return_button{Button(12,12,0,0,"resources/button_quit.png")} // Placeholder icon for "Return"
{
  window.setFramerateLimit(60);

  caviar.loadFromFile("resources/CaviarDreams.ttf");

  highscore_text.setFont(caviar);
  highscore_text.setCharacterSize(35);
  highscore_text.setStyle(sf::Text::Bold);
  highscore_text.setColor(sf::Color(255,255,255));
  highscore_text.setPosition(450,50);
  highscore_text.setString("!!! Highscore List !!!");

  score_text1.setFont(caviar);
  score_text1.setCharacterSize(20);
  score_text1.setStyle(sf::Text::Bold);
  score_text1.setColor(sf::Color(255,255,255));
  score_text1.setPosition(400,150);

  score_text2.setFont(caviar);
  score_text2.setCharacterSize(20);
  score_text2.setStyle(sf::Text::Bold);
  score_text2.setColor(sf::Color(255,255,255));
  score_text2.setPosition(400,200);

  score_text3.setFont(caviar);
  score_text3.setCharacterSize(20);
  score_text3.setStyle(sf::Text::Bold);
  score_text3.setColor(sf::Color(255,255,255));
  score_text3.setPosition(400,250);

  score_text4.setFont(caviar);
  score_text4.setCharacterSize(20);
  score_text4.setStyle(sf::Text::Bold);
  score_text4.setColor(sf::Color(255,255,255));
  score_text4.setPosition(400,300);

  score_text5.setFont(caviar);
  score_text5.setCharacterSize(20);
  score_text5.setStyle(sf::Text::Bold);
  score_text5.setColor(sf::Color(255,255,255));
  score_text5.setPosition(400,350);

  score_text6.setFont(caviar);
  score_text6.setCharacterSize(20);
  score_text6.setStyle(sf::Text::Bold);
  score_text6.setColor(sf::Color(255,255,255));
  score_text6.setPosition(400,400);

  score_text7.setFont(caviar);
  score_text7.setCharacterSize(20);
  score_text7.setStyle(sf::Text::Bold);
  score_text7.setColor(sf::Color(255,255,255));
  score_text7.setPosition(400,450);

  score_text8.setFont(caviar);
  score_text8.setCharacterSize(20);
  score_text8.setStyle(sf::Text::Bold);
  score_text8.setColor(sf::Color(255,255,255));
  score_text8.setPosition(400,500);

  score_text9.setFont(caviar);
  score_text9.setCharacterSize(20);
  score_text9.setStyle(sf::Text::Bold);
  score_text9.setColor(sf::Color(255,255,255));
  score_text9.setPosition(400,550);

  score_text10.setFont(caviar);
  score_text10.setCharacterSize(20);
  score_text10.setStyle(sf::Text::Bold);
  score_text10.setColor(sf::Color(255,255,255));
  score_text10.setPosition(400,600);

  show_score();
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
		    // Måste åtgärdas! Går man från Highscorelistan till Menyn kan man inte spara sin
		    // spelomgång efteråt
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
  window.draw(return_button.get_sprite());
  window.draw(highscore_text);
  window.draw(score_text1);
  window.draw(score_text2);
  window.draw(score_text3);
  window.draw(score_text4);
  window.draw(score_text5);
  window.draw(score_text6);
  window.draw(score_text7);
  window.draw(score_text8);
  window.draw(score_text9);
  window.draw(score_text10);
  window.display();
}


void High_Score_List::add_entry(unique_ptr<Entry> entry)
{
  cout << "Kommer hit!!!!" << endl;
  int score = entry->get_score();

  if( entries.size() == 0 )
    {
      entries.push_back(move(entry));
    }
  
  for(unsigned i{} ; i != entries.size() ; i++)
    {
      cout << "Add entry" << endl;
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

  save_to_file();
}

void High_Score_List::show_score()
{
  ifstream infile;
  string line1;
  string line2;
  string line3;
  string line4;
  string line5;
  string line6;
  string line7;
  string line8;
  string line9;
  string line10;
  infile.open("resources/Highscorelist.txt");
  getline(infile,line1);
  score_text1.setString(line1);
  getline(infile,line2);
  score_text2.setString(line2);
  getline(infile,line3);
  score_text3.setString(line3);
  getline(infile,line4);
  score_text4.setString(line4);
  getline(infile,line5);
  score_text5.setString(line5);
  getline(infile,line6);
  score_text6.setString(line6);
  getline(infile,line7);
  score_text7.setString(line7);
  getline(infile,line8);
  score_text8.setString(line8);
  getline(infile,line9);
  score_text9.setString(line9);
  getline(infile,line10);
  score_text10.setString(line10);
  infile.close();
}

void High_Score_List::save_to_file()
{
  // Fungerar inte som tänkt eftersom spelet avslutas. Vektorn entries får max 1 element
  cout << entries.size() << endl;
  for(unsigned i{} ; i != entries.size() ; i++)
    {
      string new_entry = entries.at(i)->to_string();
      ofstream outfile;
      outfile.open("resources/Highscorelist.txt");
      outfile << new_entry << '\n' << endl;
      cout << new_entry << endl;
      outfile.close();
    }

  /*
  // For testing purposes
  ofstream outfile;
  outfile.open("resources/Highscorelist.txt");
  string test = to_string();
  outfile << test << endl;
  string test2 = "CoolKille2 Technodancer -4 2017-12-12";
  outfile << test2 << endl;
  string test3 = "CoolKille2 Technodancer -4 2017-12-01";
  outfile << test3 << endl;
  string test4 = "CoolKille2 Technodancer -4 2017-12-10";
  outfile << test4 << endl;
  string test5 = "CoolKille2 Technodancer 6 2017-12-13";
  outfile << test5 << endl;
  string test6 = "CoolKille2 Technodancer 1 2017-12-18";
  outfile << test6 << endl;
  string test7 = "CoolKille2 Technodancer -8 2017-12-19";
  outfile << test7 << endl;
  string test8 = "Hejsvejsmannen Technodancer -4 2017-12-24";
  outfile << test8 << endl;
  string test9 = "CoolKille3 Technodancer -4 2017-12-31";
  outfile << test9 << endl;
  string test10 = "CoolKille2 Technodancer -4 2017-12-30";
  outfile << test10 << endl;
  outfile.close();
  */
}

