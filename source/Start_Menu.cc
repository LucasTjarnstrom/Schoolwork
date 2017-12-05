#include <SFML/Graphics.hpp>
#include "Start_Menu.h"
#include <iostream>

using namespace std;

Start_Menu::Start_Menu()
  : window(sf::VideoMode(1280, 720), "Start menu"),
    start_button{Button(12,12,0,0,"resources/button.png")}
{
  window.setFramerateLimit(60);
}

void Start_Menu::run()
{
  while (window.isOpen())
    {
      process_events();
      render();
    }
}

void Start_Menu::process_events()
{
  sf::Event event;
  while (window.pollEvent(event))
    {
      switch(event.type)
	{
	  //window closed
	case sf::Event::Closed:
	  {
	    window.close();
	  }
	case sf::Event::MouseMoved:
	  {
	    cout << "new mouse x: " << event.mouseMove.x << endl;
	    cout << "new mouse y: " << event.mouseMove.y << endl;
	    break;
	  }
	case sf::Event::MouseButtonPressed:
	  {
	    if (event.mouseButton.button == sf::Mouse::Left)
	      {
		if( sf::Mouse::getPosition(window).x < 600 && sf::Mouse::getPosition(window).y < 170 )
		  {
		    cout << "Click!" << endl;
		  }
	      }

	    /*

	    if ( (event.mouseMove.y < 170 && event.mouseMove.x < 600) && (event.mouseButton.button == sf::Mouse::Left) )
	      {
		cout << "Clicked button!" << endl;
	      } 


	    if ( sf::Mouse::getPosition(window).x > sf::Sprite::getGlobalBounds(start_button).left )
	      {
		cout << "In correct area" << endl;
	      }

	    */

	    break;
	    }
	default:
	  break;
	}
    }
}

void Start_Menu::render()
{
  start_button.get_sprite().setPosition(0,0);
  window.clear(sf::Color(10,110,191));
  window.draw(start_button.get_sprite());
  window.display();
}
