/*
 * Game.h
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
    Game();
    void run(std::string user_choice);

private:
    void process_events();
    void update();
    void render();
    void handle_player_input(sf::Keyboard::Key key, bool is_pressed);

    sf::RenderWindow window {};
    Player player {};
    
    std::string movement {};
    bool move_left {false};
    bool move_right {false};

};

#endif