#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

int main()
{
    sf::Color c(252,10,191,255);
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    //window.setVerticalSyncEnabled(true); // window will run at the same freq as monitor
    window.setFramerateLimit(60); // window will run at set framerate
    sf::CircleShape shape(350.f);
    shape.setFillColor(c);

    sf::Texture texture;
    texture.loadFromFile("resources/image.png");
    texture.setRepeated(true);
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    //sprite.setColor(sf::Color(10,110,191));

    sprite.setPosition(sf::Vector2f(500, 220));
    //sprite.scale(sf::Vector2f(1.5f, 3.f));
    
    int i = 0;
    int j = 0;
    //window.setPosition(sf::Vector2i(i,j));


    Player PC (12,12,0,0,"resources/image.png");
    sf::Vector2f pos(PC.get_x_pos(), PC.get_y_pos());
    
    sf::Clock clock;
    while (window.isOpen())
    {
      PC.set_x_velocity(0);
        //i = rand() % 100;
	//j = rand() % 100;
	//window.setPosition(sf::Vector2i(i,j));

	sprite.setPosition(sf::Vector2f(500 + i, 200 + j));

        sf::Event event;
        while (window.pollEvent(event))
        {
	    switch(event.type)
	    {
		//windows closed
	    case sf::Event::Closed:
		window.close();
		
	    case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Escape)
		{
		    std::cout << "the escape key was pressed" << std::endl;
		    std::cout << "control:" << event.key.control << std::endl;
		    std::cout << "alt:" << event.key.alt << std::endl;
		    std::cout << "shift:" << event.key.shift << std::endl;
		    std::cout << "system:" << event.key.system << std::endl;
		    window.close();
		}

		if (event.key.code == sf::Keyboard::D)
		  PC.set_x_velocity(1);

		if (event.key.code == sf::Keyboard::A)
		  PC.set_x_velocity(-1);
		    
	    case sf::Event::MouseMoved:
		{
		    //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
		    //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
		    break;
		}

		
	    case sf::Event::TextEntered:
	    {
		//if(event.text.unicode < 128)
		//    std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
		break;
	    }

	    case sf::Event::Resized:
	    {
		//std::cout << "new width: " << event.size.width << std::endl;
		//std::cout << "new height: " << event.size.height << std::endl;
		break;
	    }

	    default:
		break;
		
	    }
        }

	PC.get_sprite().setPosition(PC.get_x_pos(), PC.get_y_pos());
	PC.set_x_pos(PC.get_x_pos() + PC.get_x_velocity());

	cout << PC.get_sprite().getPosition().x << endl;
	cout << PC.get_x_pos() << endl;

	PC.set_y_velocity(PC.get_y_velocity() + PC.get_y_acc()); //gravity
	PC.set_y_pos(PC.get_y_pos() + PC.get_y_velocity());

        window.clear(sf::Color(10,110,191));
        //window.draw(shape);
	//window.draw(sprite);
	window.draw(PC.get_sprite());
        window.display();
	
	sf::Time elapsed = clock.getElapsedTime();
	while (elapsed.asSeconds() < 1/60) //caps the system at 60 fps
	  {
	  elapsed = clock.getElapsedTime();
	  }
	clock.restart();
    }

    return 0;
}
