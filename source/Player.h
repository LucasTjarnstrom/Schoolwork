/*
 * Player.h
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

    void set_experience(int);
    int get_experience() const;

    void save_experience();
    void load_experience();
    
    void jump() override;
    sf::Sprite attack() override;
    void move(std::string const &) override;
    void is_colliding(std::string) override;

    int attack_counter {1};

private:
    int jump_counter {1}; // får ändras senare
    int weapon_damage {};
    Player_Attack attack_ {};
    int experience {};
};

#endif 
