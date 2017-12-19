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
    std::pair<std::string,int> run(std::string user_choice);
 
    void create_enemy(std::string type, int xp, int yp, int xs, int ys);
    std::vector<std::unique_ptr<Enemy>>& get_enemies();
    void set_enemies(std::vector<std::unique_ptr<Enemy>>&);
    void add_enemy(std::unique_ptr<Enemy>);

private:
    std::string process_events();
    void update();
    void render();
    std::string handle_player_input(sf::Keyboard::Key key, bool is_pressed);
    sf::Text draw_player_health();
    sf::Text draw_player_attack();
    sf::Text draw_player_score();
    sf::Text draw_name_entry();
    
    sf::RenderWindow window {};
    sf::Clock clock {};
    Player player {};
    Map map {};
    std::vector<std::unique_ptr<Enemy>> enemies {};

    sf::Text player_health {};
    sf::Text player_attack {};
    sf::Text player_score {};
    sf::Font old_london {};
    sf::Text enter_your_name {};
    sf::Text name_entry {};
    sf::Text game_lost_text {};
    sf::Text game_won_text {};
    sf::Font arial {};
    
    sf::Texture bgtexture {};
    sf::Sprite bgsprite {};
    sf::Texture endgametexture {};
    sf::Sprite endgamesprite {};
    
    std::string movement {};
    bool move_left {false};
    bool move_right {false};
    bool jump {false};
    bool attacking {false};
    bool game_won {false};
    bool player_dead {false};
    bool player_recently_hit {false};
};

#endif
