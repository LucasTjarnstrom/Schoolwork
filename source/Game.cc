/*
 * Game.cc
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <memory>

#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Floor.h"
#include "Wall.h"
#include "Collision.h"

using namespace std;

Game::Game()
    : window(sf::VideoMode(1280, 720), "SFML works!"),
      player{Player(70,0,0,0,"resources/player.png")}
{
    window.setFramerateLimit(60); // FPS set to 60
    
    unique_ptr<Floor> temp1 = make_unique<Floor>(0,400,0,0,"resources/floor2.png");
    map.get_environments().push_back(move(temp1));
    unique_ptr<Wall> temp2 = make_unique<Wall>(0,-100,0,0,"resources/wall2.png");
    map.get_environments().push_back(move(temp2));
    unique_ptr<Wall> temp3 = make_unique<Wall>(500,-100,0,0,"resources/wall2.png");
    map.get_environments().push_back(move(temp3));
}

void Game::run(string user_choice)
{   
  if ( user_choice == "Start game" )
    {
      while (window.isOpen())
	{
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
	throw logic_error("Start_Menu returns invalid string!");
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

    //cout << "Physics updated" << endl;
   
}

void Game::render()
{
  for (auto it = map.get_environments().begin(); it != map.get_environments().end(); it++)
    {
      if (Collision::BoundingBoxTest(player.draw_this(), (*it)->draw_this())) //Checks if player is colliding with anything
	{
	  if (dynamic_cast<Wall*> ((*it).get()) != nullptr) // Checks if player is colliding with a Wall
	    {
	      for (auto it2 = map.get_environments().begin(); it2 != map.get_environments().end(); it2++)
		{
		  if (Collision::BoundingBoxTest(player.draw_this(), (*it2)->draw_this())) //Checks if player is colliding with another object
		    {
		      if (dynamic_cast<Floor*> ((*it2).get()) != nullptr) // Checks if the other object is a Floor
			{
			  //----------Colliding with both a Floor and a Wall----------
			  if (player.get_facing_right()) //Checks from what direction the character is colliding with the wall
			    {
			      player.set_x_pos(player.get_x_pos() - 5); //This value has to be >= the character's x-velocity.
			    }
			  else
			    {
			      player.set_x_pos(player.get_x_pos() + 5); //This value has to be >= the character's x-velocity.
			    }
			}
		      else
			{
			  //----------Colliding with a Wall----------
			  if (player.get_facing_right()) //Checks from what direction the character is colliding with the wall
			    {
			      player.set_x_pos(player.get_x_pos() - 5); //This value has to be >= the character's x-velocity.
			    }
			  else
			    {
			      player.set_x_pos(player.get_x_pos() + 5); //This value has to be >= the character's x-velocity.
			    }
			}
		    }
		}
	    }
	  else
	    {
	      //----------Colliding with a Floor----------
	      player.set_y_velocity(-0.1);
	      player.jump_counter = 1;
	    }
	}
    }
  
  window.clear(sf::Color(10,110,191));
  window.draw(player.draw_this());
  for (auto it = map.get_environments().begin(); it != map.get_environments().end(); it++)
    {
      window.draw((*it) -> draw_this());
    }
  window.display();
  //cout << "Graphics updated" << endl;
}

void Game::handle_player_input(sf::Keyboard::Key key, bool is_pressed)
{
    if (key == sf::Keyboard::A)
	move_left = is_pressed;
    else if (key == sf::Keyboard::D)
	move_right = is_pressed;
    else if (key == sf::Keyboard::Space)
    {
	if(is_pressed)
	    player.jump();
    }
}
