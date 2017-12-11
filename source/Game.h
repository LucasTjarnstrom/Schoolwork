/*
 * Game.h
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

class Game
{
public:
    Game();
    void run(std::string user_choice);
  
    std::vector<std::unique_ptr<Enemy>>& get_enemies();
    void set_enemies(std::vector<std::unique_ptr<Enemy>>&);
    void add_enemy(std::unique_ptr<Enemy>&);
  

private:
    void process_events();
    void update();
    void render();
    void handle_player_input(sf::Keyboard::Key key, bool is_pressed);
    sf::Text draw_player_health();
    sf::Text draw_player_attack();

    sf::RenderWindow window {};
    Player player {};
    Map map {};
    std::vector<std::unique_ptr<Enemy>> enemies {};

    sf::Text player_health {};
    sf::Text player_attack {};
    sf::Font arial {};
    
    std::string movement {};
    bool move_left {false};
    bool move_right {false};
    bool jump {false};
    bool attacking {false};
    
};

#endif
