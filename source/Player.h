/*
 * IDENTIFICATION 
 * File: Player.h 
 * Module: Character
 * 
 * DESCRIPTION
 * This class handles the main way the user interacts with
 * the system; through a player character which acts as a 
 * surrogate for the user in the game loop. 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Player_Attack.h"
#include <string>

class Player : public Character
{
public:
    Player() = default;           // default constructor
    Player(int);                  // constructor
    Player(double,double,double,double,std::string);

    sf::Sprite draw_this() override;

    void set_weapon_damage(int);
    int get_weapon_damage() const;

    void set_attack_counter(int);
    int get_attack_counter() const;

    void set_experience(int);
    int get_experience() const;

    void save_experience();
    void load_experience();
    
    void jump() override;
    sf::Sprite attack() override;
    void move(std::string const &) override;
    void is_colliding(std::string) override;

private:
    int jump_counter {1};    
    int attack_counter {1};
    int weapon_damage {};
    Player_Attack attack_ {};
    int experience {};
};

#endif 
