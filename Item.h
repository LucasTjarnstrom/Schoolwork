/*
 * Item.h
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item : public Drawable
{
public:
    Item() = default;                     // default constructor
    virtual ~Item() = default;            // destructor
    Item(std::string,                     // constructor
	int,int,int,int,sprite);                    
    Item(Item const & it)                 // copy constructor
    Item(Item && it);                     // move constructor
    Item& operator= (Item const & it);    // copy assignment
    Item& operator= (Item && it);         // move assignment

    virtual std::string get_name() const; // set och get_name behöver inte vara abstrakta,
    virtual void set_name(std::string);   // de kan implementeras här och ärvas
    virtual void activate() const = 0;  // const för att item i sig förändras inte,
                                        // men player gör det
protected:
    std::string name {};
}

#endif
