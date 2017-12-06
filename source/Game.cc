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

void Game::run()
{   
    //sf::Clock clock;
    while (window.isOpen())
    {
	player.set_x_velocity(0);
	process_events();
	update();
	render();
	
        /*sf::Time elapsed = clock.getElapsedTime();
    	while (elapsed.asSeconds() < 1/60) //caps the system at 60 fps
	{
	    elapsed = clock.getElapsedTime();
	}
    	clock.restart();*/
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
	player.set_x_velocity(-1);
    if(move_right)
	player.set_x_velocity(1);

    player.set_x_pos(player.get_x_pos() + player.get_x_velocity());
    
    player.set_y_velocity(player.get_y_velocity() + player.get_y_acc()); //gravity
    player.set_y_pos(player.get_y_pos() + player.get_y_velocity());
    
    cout << "Physics updated" << endl;
   
}
void Game::render()
{
    player.get_sprite().setPosition(player.get_x_pos(), player.get_y_pos());

    window.clear(sf::Color(10,110,191));
    window.draw(player.get_sprite());
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
