/*
 * Character.h
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Drawable.h"

class Character : public Drawable
{
public:
    Character() = default; // default constructor
    Character(int); // constructor

    Character(double,double,double,double,std::string);
    virtual ~Character() = default; // destructor

    // Setters and getters
    virtual void set_vitality(int);
    virtual int get_vitality() const;

    virtual void set_current_health(int);
    virtual int get_current_health() const;

    virtual void set_facing_right(bool);
    virtual bool get_facing_right();

    virtual void set_strength(int);
    virtual int get_strength() const;

    virtual void set_score(int);
    virtual int get_score() const;

    // "Player operations" are pure virtual because the method implementation will not be uniform across subclasses
    virtual void jump() = 0; 
    virtual sf::Sprite attack() = 0;
    virtual void move(std::string const &) = 0;

protected:
    int strength {};
    int vitality {};
    int current_health {};
    bool facing_right {};
    bool faced_right {};
    int score {};
};

#endif 
