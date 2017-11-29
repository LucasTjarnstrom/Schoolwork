/*
 * Game.h
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    //void process_events();
    //void update();
    //void render();
    //void handle_player_input(sf::Keyboard::Key key, bool is_pressed);

    sf::RenderWindow window {};
    //bool move_left {false};
    //bool move_right {false};

};

#endif
