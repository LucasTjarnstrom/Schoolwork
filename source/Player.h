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
    
    void jump() override;
    sf::Sprite attack() override;
    void move(std::string const &) override;
    //void take_damage(int) override;
    void is_colliding(std::string) override;

//private:
    int jump_counter {1}; // får ändras senare
    int attack_counter {1};
    int weapon_damage {};
    Player_Attack attack_ {};
};

#endif 
