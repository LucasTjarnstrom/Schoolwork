/*
 * Drawable.h
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Drawable
{
public:
    Drawable() = default;                       // default constructor
    virtual ~Drawable() = default;              // destructor
    Drawable(int,int,int,int,std::string);      // constructor 
    //Drawable(Drawable const & dr)               // copy constructor
    //Drawable(Drawable && dr);                   // move constructor
    //Drawable& operator= (Drawable const & it);  // copy assignment
    //Drawable& operator= (Drawable && it);       // move assignment
    
    // Position
    virtual int get_x_pos() const;
    virtual void set_x_pos(int);
    virtual int get_y_pos() const;
    virtual void set_y_pos(int);
    // Velocity, acceleration
    virtual int get_x_velocity() const;
    virtual void set_x_velocity(int);
    virtual int get_y_velocity() const;
    virtual void set_y_velocity(int);
    virtual int get_y_acc() const;
    virtual void set_y_acc(int);
    // Size
    virtual int get_x_size() const;
    virtual void set_x_size(int);
    virtual int get_y_size() const;
    virtual void set_y_size(int);

    virtual sf::Sprite& get_sprite();

    //virtual void draw_this(canvas) = 0;

protected:
    int x_pos {};
    int y_pos {};
    int x_velocity {0};
    int y_velocity {0};
    int y_acc {-10}; // där g ska vara tyngdkonstanten av något slag i negativ y, fys. kord.p.
    int x_size {};
    int y_size {};
    sf::Texture texture {};
    sf::Sprite sprite {}; // en datamedlem av typen sprite som heter sprite
};

#endif
