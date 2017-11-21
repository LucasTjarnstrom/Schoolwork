/*
 * Weapon.h
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon : public Item
{
public:
    Weapon() = default;                     // default constructor
    Weapon(std::string,                     // constructor
	   int,int,int,int,sprite);                  
    Weapon(Item const & it)                 // copy constructor
    Weapon(Weapon && it);                   // move constructor
    Weapon& operator= (Weapon const & it);  // copy assignment
    Weapon& operator= (Weapon && it);       // move assignment

    std::string get_name() const; // same functionality as get_name in Item
    void set_name(std::string);   // same functionality as set_name in Item
    void activate() const override;  

protected:
    std::string name {};
}

#endif
