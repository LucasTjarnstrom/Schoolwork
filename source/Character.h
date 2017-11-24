/*
 * Character.h
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character// : public Drawable
{
public:
    Character() = default; // default constructor
    Character(int); // constructor
    virtual ~Character() = default; // destructor

    //Character(Character const& it); // copy constructor
    //Character(Character && it); // move constructor
    //Character& operator=(Character const& it); // copy assignment
    //Character& operator=(Character && it); // move assignment

    // Setters and getters do not have to be virtual
    void set_vitality(int);
    int get_vitality() const;

    void set_current_health(int);
    int get_current_health() const;

    // "Player operations" are pure virtual because the method implementation will not be uniform across subclasses
    //virtual void jump() = 0; 
    //virtual void attack() = 0;
    //virtual void move(const& std::string) = 0;
    //virtual void take_damage(int) = 0;

protected:
    int strength {};
    int vitality {};
    int current_health {};
  
};

#endif 
