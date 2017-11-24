/*
 * Usable.h
 */

#ifndef USABLE_H
#define USABLE_H

#include <string>

class Usable : public Item
{
public:
    Usable() = default;                     // default constructor
    Usable(std::string,                     // constructor
	   int,int,int,int,sprite);                    
    Usable(Item const & it)                 // copy constructor
    Usable(Usable && it);                   // move constructor
    Usable& operator= (Usable const & it);  // copy assignment
    Usable& operator= (Usable && it);       // move assignment

    std::string get_name() const; // same functionality as get_name in Item
    void set_name(std::string);   // same functionality as set_name in Item
    void activate() const override;  

protected:
    std::string name {};
}

#endif
