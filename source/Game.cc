/*
 * Game.cc
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game()
    : window(sf::VideoMode(1280, 720), "SFML works!"),
      player{Player(12,12,0,0,"resources/image.png")}
{
    window.setFramerateLimit(60); // FPS set to 60
}

void Game::run(string user_choice)
{   
  if ( user_choice == "Start game" )
    {
      while (window.isOpen())
	{
	  player.set_x_velocity(0);
	  process_events();
	  update();
	  render();
	}   
    }

  else if ( user_choice == "Continue" )
    {
      cout << "Continue game" << endl;
      return;
    }

  else if ( user_choice == "Show high scores" )
    {
      cout << "Show high scores" << endl;
      return;
    }
  
  else if(user_choice == "Quit" )
    {
      return;
    }

  else
    {
      cout << "This should not happen!" << endl;
      return;
    }
}

void Game::process_events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
	switch(event.type)
	{
	    //windows closed
	case sf::Event::Closed:
	    window.close();
	    
	case sf::Event::KeyPressed:
	    if (event.key.code == sf::Keyboard::Escape) //press escape -> close window
	    {
	    	window.close();
	    } else
		handle_player_input(event.key.code, true);
	    break;
	    
	case sf::Event::KeyReleased:
	    handle_player_input(event.key.code, false);
	    break;
	    	    
	case sf::Event::MouseMoved:
	{
	    //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
	    //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
	    break;
	}
	default:
	    break;	
	}
    }
    
}

void Game::update()
{
    if(move_left)
	movement = "left";
    else if(move_right)
	movement = "right";
    else
	movement = "nothing";

    player.move(movement);

    cout << "Physics updated" << endl;
   
}
void Game::render()
{
    window.clear(sf::Color(10,110,191));
    window.draw(player.draw_this());
    window.display();

    cout << "Graphics updated" << endl;
}

void Game::handle_player_input(sf::Keyboard::Key key, bool is_pressed)
{
    if (key == sf::Keyboard::A)
	move_left = is_pressed;
    else if (key == sf::Keyboard::D)
	move_right = is_pressed;
}
