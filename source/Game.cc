/*
 * Game.cc
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <sstream>
#include <vector>

#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Floor.h"
#include "Wall.h"
#include "Collision.h"
#include "High_Score_List.h"
#include "Enemy.h"

using namespace std;

Game::Game()
    : window(sf::VideoMode(1280, 720), "SFML works!"),
      player{Player(200,150,0,0,"resources/player.png")}

{
    player.set_vitality(10);
    player.set_current_health(player.get_vitality());
    player.set_strength(1);

    window.setFramerateLimit(60); // FPS set to 60

    // Font
    arial.loadFromFile("resources/arial.ttf");
    
    // Setting up GUI for displaying player's health
    player_health.setFont(arial);
    player_health.setCharacterSize(30);
    player_health.setStyle(sf::Text::Bold);
    player_health.setColor(sf::Color(255, 255, 255));

    // Setting up GUI for displaying player's strength + weapon damage
    player_attack.setFont(arial);
    player_attack.setCharacterSize(30);
    player_attack.setStyle(sf::Text::Bold);
    player_attack.setColor(sf::Color(255, 255, 255));
    player_attack.setPosition(960,0);
    
    unique_ptr<Floor> temp1 = make_unique<Floor>(0,400,0,0,"resources/floor2.png");
    map.get_environments().push_back(move(temp1));
    unique_ptr<Wall> temp2 = make_unique<Wall>(0,-100,0,0,"resources/wall2.png");
    map.get_environments().push_back(move(temp2));
    unique_ptr<Wall> temp3 = make_unique<Wall>(500,-100,0,0,"resources/wall2.png");
    map.get_environments().push_back(move(temp3));

    unique_ptr<Enemy> temp4 = make_unique<Enemy>(200,200,0,0,"resources/enemy.png");
    enemies.push_back(move(temp4));
    
}

vector<unique_ptr<Enemy>>& Game::get_enemies()
{
  return enemies;
}

void Game::set_enemies(vector<unique_ptr<Enemy>>& other)
{
  enemies = move(other);
}

void Game::add_enemy(unique_ptr<Enemy>& e)
{
  enemies.push_back(move(e));
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
      window.close();
      High_Score_List high_score_list {};
      high_score_list.run();
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

    for (auto it = enemies.begin(); it != enemies.end(); it++)
      {
	(*it) -> move("nothing");
      }
}

void Game::render()
{
  //----------PLAYER COLLISION WITH ENVIRONMENT----------
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
			    player.is_colliding("floor_wall");
			}
		      else
		      {
			  //----------Colliding with a Wall----------
			  player.is_colliding("wall");	  
		      }
		    }
		}
	    }
	  else
	  {
	      //----------Colliding with a Floor----------
	      player.is_colliding("floor");	      
	  }
	}
    }

  //----------ENEMY COLLISION WITH ENVIRONMENT----------
  for (auto enemyit = enemies.begin(); enemyit != enemies.end(); enemyit++)
    {
      for (auto it = map.get_environments().begin(); it != map.get_environments().end(); it++)
	{
	  if (Collision::BoundingBoxTest((*enemyit)->draw_this(), (*it)->draw_this())) //Checks if the enemy is colliding with anything
	    {
	      if (dynamic_cast<Wall*> ((*it).get()) != nullptr) // Checks if the enemy is colliding with a Wall
		{
		  for (auto it2 = map.get_environments().begin(); it2 != map.get_environments().end(); it2++)
		    {
		      if (Collision::BoundingBoxTest((*enemyit)->draw_this(), (*it2)->draw_this())) //Checks if the enemy is colliding with another object
			{
			  if (dynamic_cast<Floor*> ((*it2).get()) != nullptr) // Checks if the other object is a Floor
			    {
			      //----------Colliding with both a Floor and a Wall----------
			      if ((*enemyit)->get_facing_right()) //Checks from what direction the character is colliding with the wall
				{
				  (*enemyit)->set_x_pos((*enemyit)->get_x_pos() - 5); //This value has to be >= the character's x-velocity.
				}
			      else
				{
				  (*enemyit)->set_x_pos((*enemyit)->get_x_pos() + 5); //This value has to be >= the character's x-velocity.
				}
			    }
			  else
			    {
			      //----------Colliding with a Wall----------
			      if ((*enemyit)->get_facing_right()) //Checks from what direction the character is colliding with the wall
				{
				  (*enemyit)->set_x_pos((*enemyit)->get_x_pos() - 5); //This value has to be >= the character's x-velocity.
				}
			      else
				{
				  (*enemyit)->set_x_pos((*enemyit)->get_x_pos() + 5); //This value has to be >= the character's x-velocity.
				}
			    }
			}
		    }
		}
	      else
		{
		  //----------Colliding with a Floor----------
		  (*enemyit)->set_y_velocity(-0.1);
		}
	    }
	}
    }
    
    
    window.clear(sf::Color(10,110,191));
    window.draw(player.draw_this());
    for (auto it = enemies.begin(); it != enemies.end(); it++)
      {
	window.draw((*it) -> draw_this());
      }
    for (auto it = map.get_environments().begin(); it != map.get_environments().end(); it++)
    {
	window.draw((*it) -> draw_this());
    }
    window.draw(draw_player_health());
    window.draw(draw_player_attack());

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

sf::Text Game::draw_player_health()
{
    stringstream ss;
    ss << player.get_current_health() << "/" << player.get_vitality();
    player_health.setString(ss.str());
    player_health.setPosition(player.get_x_pos() - 40, player.get_y_pos() - 40);

    return player_health;
}

sf::Text Game::draw_player_attack()
{
    stringstream ss;
    ss << "Your attack is: " << player.get_strength() << " + " << player.get_weapon_damage();
    player_attack.setString(ss.str());

    return player_attack;
}
