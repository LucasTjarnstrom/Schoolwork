#include <SFML/Graphics.hpp>
#include "Start_Menu.h"
#include <iostream>

using namespace std;

Start_Menu::Start_Menu()
    : window(sf::VideoMode(1280, 720), "Start menu"),
    start_button{Button(12,12,0,0,"resources/button_start-game.png")},
    high_score_button{Button(12,12,0,0,"resources/button_high-scores.png")},
    quit_button{Button(12,12,0,0,"resources/button_quit.png")}
{
    window.setFramerateLimit(60);

    // Background
    background_texture.loadFromFile("resources/menubackground.png");
    background_sprite.setTexture(background_texture);

    // Font
    font.loadFromFile("resources/OldLondon.ttf");
/*
    // Title
    title.setFont(font);
    title.setCharacterSize(180);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color(255,255,255));
    title.setPosition(170,40);
    title.setString("Lorem Ipsum"); */
}

pair <string,bool> Start_Menu::run()
{
  string user_choice{};
  process_events();
  while (window.isOpen())
    {
      user_choice = process_events();
      if (user_choice != "")
	{
	  window.close();
	  if (user_choice == "Quit")
	    return make_pair(user_choice,true);
	  else
	    return make_pair(user_choice,false);
	}
      render();
    }
  return make_pair("",false);
}

string Start_Menu::process_events()
{
  sf::Event event;
  while (window.pollEvent(event))
    {
      switch(event.type)
	{
	case sf::Event::Closed:
	  {
	    return "Quit";
	  }
	case sf::Event::KeyPressed:
	  if (event.key.code == sf::Keyboard::Escape) //press escape -> close window
	    {
	      return "Quit";
	    } else if (event.key.code == sf::Keyboard::Return)
	    return "Start game";
	case sf::Event::MouseButtonPressed:
	  {
	    if (event.mouseButton.button == sf::Mouse::Left)
	      {
		if(sf::Mouse::getPosition(window).x > 490 && sf::Mouse::getPosition(window).x < 790 &&
		   sf::Mouse::getPosition(window).y > 270 && sf::Mouse::getPosition(window).y < 390)
		  {
		    return "Start game";
		  }
		else if (sf::Mouse::getPosition(window).x > 490 && sf::Mouse::getPosition(window).x < 790 &&
			 sf::Mouse::getPosition(window).y > 400 && sf::Mouse::getPosition(window).y < 520)
		  {
		    return "Show high scores";
		  }
		else if (sf::Mouse::getPosition(window).x > 490 && sf::Mouse::getPosition(window).x < 790 &&
			 sf::Mouse::getPosition(window).y > 530 && sf::Mouse::getPosition(window).y < 650)
		  {
		    return "Quit";
		  }
	      }
	    break;
	  }
	default:
	  break;
	}
    }
  return "";
}

void Start_Menu::render()
{
  start_button.get_sprite().setPosition(490,270);
  high_score_button.get_sprite().setPosition(490,400);
  quit_button.get_sprite().setPosition(490,530);
  window.clear(sf::Color(10,110,191));
  window.draw(background_sprite);
  window.draw(title);
  window.draw(start_button.get_sprite());
  window.draw(high_score_button.get_sprite());
  window.draw(quit_button.get_sprite());
  window.display();
}
