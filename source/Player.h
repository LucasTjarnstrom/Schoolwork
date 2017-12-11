/*
 * Player.h
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
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
    //void attack() override;
    void move(std::string const &) override;
    //void take_damage(int) override;
    void is_colliding() override;
    void is_colliding(std::string);

//private:
    int jump_counter {1}; // får ändras senare
    int weapon_damage {};
    

};

#endif 
