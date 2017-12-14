/*
 * Enemy.h
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>

class Enemy : public Character
{
public:
    Enemy(double,double,double,double,std::string);

    sf::Sprite draw_this() override;

    void jump() override;
    sf::Sprite attack() override;
    void move(std::string const &) override;
    void is_colliding(std::string) override;

    sf::Text health_to_text();
    void set_font(sf::Font);

    sf::Text health_text {};
    void set_facing_right(bool b);
    bool get_facing_right();
};

#endif 
