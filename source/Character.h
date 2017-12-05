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

    //Character(Character const& it); // copy constructor
    //Character(Character && it); // move constructor
    //Character& operator=(Character const& it); // copy assignment
    //Character& operator=(Character && it); // move assignment

    // Setters and getters
    virtual void set_vitality(int);
    virtual int get_vitality() const;

    virtual void set_current_health(int);
    virtual int get_current_health() const;

    // "Player operations" are pure virtual because the method implementation will not be uniform across subclasses
    //virtual void jump() = 0; 
    //virtual void attack() = 0;
    //virtual void move(std::string const &) = 0;
    //virtual void take_damage(int) = 0;

protected:
    int strength {};
    int vitality {};
    int current_health {};
};

#endif 
