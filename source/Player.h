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
<<<<<<< HEAD
    Player(double,double,double,double,std::string);
=======
    Player(int,int,int,int,int,std::string);
>>>>>>> master

    //void jump() override;
    //void attack() override;
    //void move(std::string const &) override;
    //void take_damage(int) override;

};

#endif 
