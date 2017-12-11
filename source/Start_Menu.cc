#include <SFML/Graphics.hpp>
#include "Start_Menu.h"
#include <iostream>

using namespace std;

Start_Menu::Start_Menu()
    : window(sf::VideoMode(1280, 720), "Start menu"),
    start_button{Button(12,12,0,0,"resources/button_start-game.png")},
    continue_button{Button(12,12,0,0,"resources/button_continue.png")},
    high_score_button{Button(12,12,0,0,"resources/button_high-scores.png")},
    quit_button{Button(12,12,0,0,"resources/button_quit.png")}
{
    window.setFramerateLimit(60);    
}

string Start_Menu::run()
{
  string user_choice{};
  process_events();
  while (window.isOpen())
    {
      user_choice = process_events();
      if (user_choice != "")
	{
	  window.close();
	  return user_choice;
	}
      render();
    }
  return "";
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
		if(sf::Mouse::getPosition(window).x > 560 && sf::Mouse::getPosition(window).x < 720 &&
		   sf::Mouse::getPosition(window).y > 300 && sf::Mouse::getPosition(window).y < 350)
		  {
		    return "Start game";
		  }
		else if (sf::Mouse::getPosition(window).x > 560 && sf::Mouse::getPosition(window).x < 720 &&
			 sf::Mouse::getPosition(window).y > 360 && sf::Mouse::getPosition(window).y < 410)
		  {
		    return "Continue";
		  }
		else if (sf::Mouse::getPosition(window).x > 560 && sf::Mouse::getPosition(window).x < 720 &&
			 sf::Mouse::getPosition(window).y > 420 && sf::Mouse::getPosition(window).y < 470)
		  {
		    return "Show high scores";
		  }
		else if (sf::Mouse::getPosition(window).x > 560 && sf::Mouse::getPosition(window).x < 720 &&
			 sf::Mouse::getPosition(window).y > 480 && sf::Mouse::getPosition(window).y < 530)
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
  start_button.get_sprite().setPosition(560,300);
  continue_button.get_sprite().setPosition(560,360);
  high_score_button.get_sprite().setPosition(560,420);
  quit_button.get_sprite().setPosition(560,480);
  window.clear(sf::Color(10,110,191));
  //window.draw(background);
  window.draw(start_button.get_sprite());
  window.draw(continue_button.get_sprite());
  window.draw(high_score_button.get_sprite());
  window.draw(quit_button.get_sprite());
  window.display();
}
